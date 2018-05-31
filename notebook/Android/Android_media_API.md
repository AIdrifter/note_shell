# Android Media APIs older version

The Android platform is capable of playing both audio and video media.
It is also capable of __playing media contained__ in the resources for an application,
or a __standalone file__ in the filesystem, or even __streaming media__ over a data connection.
Playback is achieved through the android.media.MediaPlayer class.

```C++
// Public Methods

static MediaPlayer create(Context context, Uri uri) // Convenience method to create a MediaPlayer for a given Uri.

int getCurrentPosition()  // Gets the current playback position.
int getDuration()         // Gets the duration of the file.

int getVideoHeight()      // Returns the height of the video.
int getVideoWidth()       // Returns the width of the video.

boolean isPlaying()       // Checks whether the MediaPlayer is playing.

void prepare()            // Prepares the player for playback, synchronously.
void prepareAsync()       // Prepares the player for playback, asynchronously.
void release()            // Releases resources associated with this MediaPlayer object.
void reset()              // Resets the MediaPlayer to its uninitialized state.
void seekTo(int msec)     // Seeks to specified time position.

void setAudioStreamType(int streamtype)             // Sets the audio stream type for this MediaPlayer.
void setDataSource(String path)                     // Sets the data source (file-path or http/rtsp URL) to use.
void setDisplay(SurfaceHolder sh)                   // Sets the SurfaceHolder to use for displaying the video portion of the media.
void setVolume(float leftVolume, float rightVolume) // Sets the volume on this player.

void pause()       // Pauses playback.
void start()       // Starts or resumes playback.
void stop()        // Stops playback after playback has been stopped or paused.

/* Playing a File */

MediaPlayer mp = new MediaPlayer();
mp.setDataSource(PATH_TO_FILE);
mp.prepare();
mp.start();

/* Playing a Raw Resource */

MediaPlayer mp = MediaPlayer.create(context, R.raw.sound_file_1);

mp.start();
```

## Part3 Android Media API
- MediaExtractor
    - 可以同一個URL，獲取容器文件的軌道數量，軌道信息(Track)。在確定了軌道信息之後，可以選擇想要解碼的軌道
    - 只能選擇一個，所以音軌和視頻軌道需要**兩個**不同MediaExtractor給兩個不同MediaCodec解碼，再從該軌道不停的讀取數據放入MediaCodec API進行解碼。

- MediaCodec
    - MediaCodec API則是創建的時候就需要選擇Codec的類型。然後編碼的時候需要安卓平台顯示視頻的Surface，**MediaCrypto**對象(如果視頻被加密的話，這個細節我會在DRM章節介紹)。
    - 一個MediaCodec在創建之後會在內部維護兩個對列(Queue),一個是InputQueue，一個是OutputQueue。類似生產者消費者的模式，MediaCodec會不停的從InputQueue獲取數據
    - (InputQueue的數據又是又MediaExtractor提供)，解碼，再把解碼之後的數據放入OutputQueue，再提供給Surface讓其視頻內容。

- reference:grafika
    - https://github.com/google/grafika

```C++
public void playWithUrl() throws IOException {
        MediaExtractor extractor = null;
        MediaCodec decoder = null;
        try {
            /**
             * 創建一個MediaExtractor對象
             */
            extractor = new MediaExtractor();
            /**
             * 設置Extractor的source,這裡可以把mp4的url傳進來,
             */
            extractor.setDataSource(context, Uri.parse(url),new HashMap<String, String>());
            /**
             * 這裡我們需要選擇我們要解析的軌道,我們在這個例子裡面只解析視頻軌道
             */
            int trackIndex = selectTrack(extractor);
            if (trackIndex < 0) {
                throw new RuntimeException("No video track found in " + url);
            }


            /**
             * 選擇視頻軌道的索引
             */
            extractor.selectTrack(trackIndex);

            /**
             * 獲取軌道的音視頻格式,這個格式和Codec有關,可以點擊MediaFormat類看看有哪些
             */
            MediaFormat format = extractor.getTrackFormat(trackIndex);
            String mime = format.getString(MediaFormat.KEY_MIME);

            /**
             * 創建一個MediaCodec對象
             */
            decoder = MediaCodec.createDecoderByType(mime);
            /**
             * 設置格式,和視頻輸出的Surface,開始解碼
             */
            decoder.configure(format, mOutputSurface, null, 0);
            decoder.start();

            doExtract(extractor, trackIndex, decoder, mFrameCallback);
        }
        catch ( Exception e ){
            e.printStackTrace();
        }

        finally {
            // release everything we grabbed
            if (decoder != null) {
                decoder.stop();
                decoder.release();
                decoder = null;
            }
            if (extractor != null) {
                extractor.release();
                extractor = null;
            }
        }
    }

```

```C++
    /**
     * 我們用Extractor獲取軌道數量,然後遍歷他們,只要找到第一個軌道是Video的就返回
     */
    private static int selectTrack(MediaExtractor extractor) {
        // Select the first video track we find, ignore the rest.
        int numTracks = extractor.getTrackCount();
        for (int i = 0; i < numTracks; i++) {
            MediaFormat format = extractor.getTrackFormat(i);
            String mime = format.getString(MediaFormat.KEY_MIME);
            if (mime.startsWith("video/")) {
                if (VERBOSE) {
                    Log.d(TAG, "Extractor selected track " + i + " (" + mime + "): " + format);
                }
                return i;
            }
        }

        return -1;
    }

```

```C++
private void doExtract(MediaExtractor extractor, int trackIndex, MediaCodec decoder,
                           FrameCallback frameCallback) {
        final int TIMEOUT_USEC = 10000;
        /**
         * 獲取MediaCodec的輸入隊列,是一個數組
         */
        ByteBuffer[] decoderInputBuffers = decoder.getInputBuffers();
        int inputChunk = 0;
        long firstInputTimeNsec = -1;

        boolean outputDone = false;
        boolean inputDone = false;
        /**
         * 用while做循環
         */
        while (!outputDone) {
            if (VERBOSE) Log.d(TAG, "loop");
            if (mIsStopRequested) {
                Log.d(TAG, "Stop requested");
                return;
            }

            // Feed more data to the decoder.
            /**
             * 不停的輸入數據知道輸入隊列滿為止
             */
            if (!inputDone) {
                /**
                 * 這個方法返回輸入隊列數組可以放數據的位置,即一個索引
                 */
                int inputBufIndex = decoder.dequeueInputBuffer(TIMEOUT_USEC);
                /**
                 * 如果輸入隊列還有位置
                 */
                if (inputBufIndex >= 0) {
                    if (firstInputTimeNsec == -1) {
                        firstInputTimeNsec = System.nanoTime();
                    }
                    ByteBuffer inputBuf = decoderInputBuffers[inputBufIndex];
                    // Read the sample data into the ByteBuffer.  This neither respects nor
                    // updates inputBuf's position, limit, etc.
                    /**
                     * 用Extractor讀取一個sample的數據,並且放入輸入隊列
                     */
                    int chunkSize = extractor.readSampleData(inputBuf, 0);
                    /**
                     * 如果chunk size是小於0,證明我們已經讀取完畢這個軌道的數據了。
                     */
                    if (chunkSize < 0) {
                        // End of stream -- send empty frame with EOS flag set.
                        decoder.queueInputBuffer(inputBufIndex, 0, 0, 0L,
                                MediaCodec.BUFFER_FLAG_END_OF_STREAM);
                        inputDone = true;
                        if (VERBOSE) Log.d(TAG, "sent input EOS");
                    }
                    else {
                        if (extractor.getSampleTrackIndex() != trackIndex) {
                            Log.w(TAG, "WEIRD: got sample from track " +
                                    extractor.getSampleTrackIndex() + ", expected " + trackIndex);
                        }
                        long presentationTimeUs = extractor.getSampleTime();
                        decoder.queueInputBuffer(inputBufIndex, 0, chunkSize,
                                presentationTimeUs, 0 /*flags*/);
                        if (VERBOSE) {
                            Log.d(TAG, "submitted frame " + inputChunk + " to dec, size=" +
                                    chunkSize);
                        }
                        inputChunk++;
                        /**
                         * Extractor移動一個sample的位置,下一次再調用extractor.readSampleData()就會讀取下一個sample
                         */
                        extractor.advance();
                    }
                } else {
                    if (VERBOSE) Log.d(TAG, "input buffer not available");
                }
            }

            if (!outputDone) {
                /**
                 * 開始把輸出隊列的數據拿出來,decodeStatus只要不是大於零的整數都是異常的現象,需要處理
                 */
                int decoderStatus = decoder.dequeueOutputBuffer(mBufferInfo, TIMEOUT_USEC);
                if (decoderStatus == MediaCodec.INFO_TRY_AGAIN_LATER) {
                    // no output available yet
                    if (VERBOSE) Log.d(TAG, "no output from decoder available");
                } else if (decoderStatus == MediaCodec.INFO_OUTPUT_BUFFERS_CHANGED) {
                    // not important for us, since we're using Surface
                    if (VERBOSE) Log.d(TAG, "decoder output buffers changed");
                } else if (decoderStatus == MediaCodec.INFO_OUTPUT_FORMAT_CHANGED) {
                    MediaFormat newFormat = decoder.getOutputFormat();
                    if (VERBOSE) Log.d(TAG, "decoder output format changed: " + newFormat);
                } else if (decoderStatus < 0) {
                    throw new RuntimeException(
                            "unexpected result from decoder.dequeueOutputBuffer: " +
                                    decoderStatus);
                } else { // decoderStatus >= 0
                    if ((mBufferInfo.flags & MediaCodec.BUFFER_FLAG_END_OF_STREAM) != 0) {
                        if (VERBOSE) Log.d(TAG, "output EOS");
                            outputDone = true;
                    }
                    boolean doRender = (mBufferInfo.size != 0);
                    if (doRender && frameCallback != null) {
                        frameCallback.preRender(mBufferInfo.presentationTimeUs);
                    }
                    /**
                     * 只要我們調用了decoder.releaseOutputBuffer(),
                     * 就會把輸出隊列的數據全部輸出到Surface上顯示,並且釋放輸出隊列的數據
                     */
                    decoder.releaseOutputBuffer(decoderStatus, doRender);
                }
            }
        }
```

## Part4 Android Adpative Streaming
### Adaptive Streaming

- HLS
    - M3u8
- DASH
    - MPD(Manifest)
        - need XML reader support it
        - mp4文件絕對地址就是mpd的path+file name = http://yt-dash-mse-test.commondatastorage.googleapis.com/media/car-20120827-88.mp4
```info
[+]mpd
    @xmlms: urn: mpeg:DSAH:schema:MMPD:2011
    @mediaPresntationDuration: PTOH3M1.635S
    @minBufferTime: PT1.5s
    @profiles: urn:mpeg:dash:profile:isoff-on-demand:2011
    @type: static

    [+]period
        @duration: PTOH3M1.63s
        @start:PTOS

        [+]adaptationset
            [+]content_component
                @contentType : video
                @id 1
            [+]representation
                    @bandwidth: 4190760 // 4190760 bit（4.2MB/s）
                    @codec: avc1.640028
                    @height: 1080    // video height
                    @id: 1
                    @mimeType: video/mp4
                    @width: 1920

                    [+]baseurl car-20120827-89.mp4 // video url
                    [+]segmentbase
                            @indexRange:674-1149

        [+]adaptationset
            [+]representation
        [+]adaptationset
            [+]representation
        [+]adaptationset
            [+]representation


        [+]adaptationset
            [+]content_component
                @contentType : video
                @id 1

        [+]adaptationset
            [+]representation
        [+]adaptationset
            [+]representation
        [+]adaptationset
            [+]representation
        [+]adaptationset
            [+]representation

```


- How does DASH play ?
    - 不同的representation都有一個bandwith的參數，這個參數規定了要使用該視頻文件的最低帶寬（如果沒記錯應該是以bit為單位。
    - 以上述mpd為例，視頻分辨率由高到低的bandwith排列是:4190760 bit（4.2MB/s） ,2073921 bit(2.1 MB/s) , 869460 bit(0.9MB/s).......
    - 播放器每下載一些內容，都會計算當前的下載速度，然後根據當前的下載速度，從最高的分辨率開始，一路遍歷直到找到合適的視頻文件。

這裡附上一段ExoPlayer的源代碼，可以更加清晰的瞭解播放器怎麼選擇不同分辨率(其實代碼非常的簡單)

```C++
private int IdealSelectedIndex(long nowMs) {

     /*
      *   Get playrer download spedd ,units for bit
      */
     long effectiveBitrate = (long) (bandwidthMeter.getBitrateEstimate() * bandwidthFraction);
     int lowestBitrateNonBlacklistedIndex = 0;
     /*
     *  The length means adaptionset's total lengths, How much representation?  Assume bandwith is order form big to small.
     */

    for (int i = 0; i < length; i++) {
      if (nowMs == Long.MIN_VALUE || !isBlacklisted(i, nowMs)) {
        /*
        *  Format is abstraction of representation
        */
        Format format = getFormat(i);
        /*
        *  Search the list, if the representation's bandwidth < download speed(effectiveBitrate), use it.
        */
        if (Math.round(format.bitrate * playbackSpeed) <= effectiveBitrate) {
          return i;
        } else {
          lowestBitrateNonBlacklistedIndex = i;
        }
      }
    }
    return lowestBitrateNonBlacklistedIndex;
  }
```
-  DASH - Fragmented MP4
    - mp4(one moov header) vs fragmented MP4

```info
     0       18   ftyp
    18      713   moov
  7154  18af35a   mdat
```

```info
         0         18       ftyp
        18        2a8       moov
       2c4        1dc       sixd  // record each mdat's position and size
       4a0        5f8       moof
       a98     1c2b05       mdat  // unit: seconds
    1c259d        5f8       moof
    1c3b95     1cd560       mdat
    3916f5        5f8       moof
    3916ed     1ac193       mdat
    53d880        5f8       moof
    53de78     101780       mdat
```

## part5 EXO player analysis and handler

- 首先ExoPlayer的入口自然是`ExoPlayerImplInternal`了，在創建ExoPlayer對象之後，ExoPlayer會通過handler，根據當前自身的狀態去不停發放消息，然後自己同時接受這些消息。
- 比如當我們調用`ExoPlayer的prepare()`方法時，其實我們就用ExoPlayer的handler去發送了一條消息`MSG_PREPARE`。


```C++
 public void prepare(MediaSource mediaSource, boolean resetPosition, boolean resetState) {
    handler
        .obtainMessage(MSG_PREPARE, resetPosition ? 1 : 0, resetState ? 1 : 0, mediaSource)
        .sendToTarget();
  }
```

```C++
  public boolean handleMessage(Message msg) {
    try {
      switch (msg.what) {
        case MSG_PREPARE:  /* First Init Media Source */
          prepareInternal(
              (MediaSource) msg.obj,
              /* resetPosition= */ msg.arg1 != 0,
              /* resetState= */ msg.arg2 != 0);
          break;
        case MSG_SET_PLAY_WHEN_READY:
          setPlayWhenReadyInternal(msg.arg1 != 0);
          break;
        case MSG_SET_REPEAT_MODE:
          setRepeatModeInternal(msg.arg1);
          break;
        case MSG_SET_SHUFFLE_ENABLED:
          setShuffleModeEnabledInternal(msg.arg1 != 0);
          break;
        case MSG_DO_SOME_WORK:  /* almost case */
          doSomeWork();
          break;
        case MSG_SEEK_TO:
          seekToInternal((SeekPosition) msg.obj);
          break;
        case MSG_SET_PLAYBACK_PARAMETERS:
          setPlaybackParametersInternal((PlaybackParameters) msg.obj);
          break;
        case MSG_SET_SEEK_PARAMETERS:
          setSeekParametersInternal((SeekParameters) msg.obj);
          break;
        case MSG_STOP:
          stopInternal(/* reset= */ msg.arg1 != 0, /* acknowledgeStop= */ true);
          break;
        case MSG_PERIOD_PREPARED:
          handlePeriodPrepared((MediaPeriod) msg.obj);
          break;

```
- 最後再叫ExoPlayer所有的**MediaSource**進行準備prepare。
- 又或者再看看`MSG_DO_SOME_WORK`這個消息發放出去之後，ExoPlayer做了什麼?
- 用for loop search all renderer, video, audio, text.

```C++
 private void doSomeWork() throws ExoPlaybackException, IOException {
    long operationStartTimeMs = clock.uptimeMillis();
    updatePeriods();
    if (!queue.hasPlayingPeriod()) {
      // We're still waiting for the first period to be prepared.
      maybeThrowPeriodPrepareError();
      scheduleNextWork(operationStartTimeMs, PREPARING_SOURCE_INTERVAL_MS);
      return;
    }
    MediaPeriodHolder playingPeriodHolder = queue.getPlayingPeriod();

    TraceUtil.beginSection("doSomeWork");

    updatePlaybackPositions();
    long rendererPositionElapsedRealtimeUs = SystemClock.elapsedRealtime() * 1000;

    playingPeriodHolder.mediaPeriod.discardBuffer(playbackInfo.positionUs - backBufferDurationUs,
        retainBackBufferFromKeyframe);

    boolean renderersEnded = true;
    boolean renderersReadyOrEnded = true;
    /* Use for loop to search all render, video, audio and text*/
    for (Renderer renderer : enabledRenderers) {
      // TODO: Each renderer should return the maximum delay before which it wishes to be called
      // again. The minimum of these values should then be used as the delay before the next
      // invocation of this method.
      renderer.render(rendererPositionUs, rendererPositionElapsedRealtimeUs); // here
      renderersEnded = renderersEnded && renderer.isEnded();
      // Determine whether the renderer is ready (or ended). We override to assume the renderer is
      // ready if it needs the next sample stream. This is necessary to avoid getting stuck if
      // tracks in the current period have uneven durations. See:
      // https://github.com/google/ExoPlayer/issues/1874
      boolean rendererReadyOrEnded = renderer.isReady() || renderer.isEnded()
          || rendererWaitingForNextStream(renderer);
      if (!rendererReadyOrEnded) {
        renderer.maybeThrowStreamError();
      }
      renderersReadyOrEnded = renderersReadyOrEnded && rendererReadyOrEnded;
    }
```

- 在創建ExoPlayer的時候我們需要傳入一個renderer數組，包括
    - Video
    - Audio
    - subtitle TextRenderer，
- 他們每個都負責渲染Render自己負責的那一部分，在ExoPlayer裡面就是這麼一個簡單的for循環，搞定。

- 在一個dosomeWork()結束之後，通過handler再發一次`MSG_DO_SOME_WORK`

```C++
  private void scheduleNextWork(long thisOperationStartTimeMs, long intervalMs) {
    handler.removeMessages(MSG_DO_SOME_WORK);
    handler.sendEmptyMessageAtTime(MSG_DO_SOME_WORK, thisOperationStartTimeMs + intervalMs);
  }
```

- 大家可以自己觀察一下其他MSG是用來幹嘛的，其實稍微看看就可以發現，都是和Playback相關的一些操作，比如seek，pause，release等等。
  那麼其實到現在為止，ExoPlayer從整體上是怎麼工作，它的大概結構就很清楚了，用一個圖來表達一下。


```info
MSG_PREPARE   MSG_RELEASE    MSG_DO_SOME_WORK          MSG_SEEK
    |               |             |                      |
    |               |             |                      |
    ---------------EXoPLayerINollnernal-------------------
                    |       |         |
           ---------|       |         -----------------------
           |                |                               |
           |MSG_PREPARE?    | MSG_DO_SOME_WORK?             | MSG_SEEK?
           |                |                               |
           |                |                               |
           |                |                               |
MediaResource         Renderer->render()            change position
           |                |                               |
           |                |                               |
           |                |                               |
           |                |                               |
    Accronding to status, send new message to EXoPLayerINollnernal,
    Most case is MSG_DO_SOME_WORK
```
- user在創建ExoPlayer之後，調用任何的方法都是發送一條message給他的handler，根據消息的不同，ExoPlayer把消息分發給不同的component
    - prepare就會把消息分發給MediaResource
    - do_some_work會把消息分發給Render , 根據當前的進度去渲染視頻，音頻和字幕。在處理完一個消息之後，會根據當前狀態發送下一個消息給ExoPlayerImplInternnal。
    - 在一個不停止的情況下，消息隊列一般都是:
        - 1.MSG_PREPARE
        - 2.MSG_PERIOD_PREPARED
        - 3.MSG_DO_SOME_WORK........不停的do some work...


- 整個ExoPlayer就是靠Handler來進行狀態維護的，不光只是ExoPlayerImplInternal這個類，其他的很多類比如LoadControl啊等等都是靠Handler來做狀態維護，和消息發放，尤其是ExoPlayer的事件分放部分，都需要用戶自己傳入一個handler。可能這對初次使用的同學會造成一定的困擾。

```C++
/**
   * @param context A context.
   * @param mediaCodecSelector A decoder selector.
   * @param allowedJoiningTimeMs The maximum duration in milliseconds for which this video renderer
   *     can attempt to seamlessly join an ongoing playback.
   * @param drmSessionManager For use with encrypted content. May be null if support for encrypted
   *     content is not required.
   * @param playClearSamplesWithoutKeys Encrypted media may contain clear (un-encrypted) regions.
   *     For example a media file may start with a short clear region so as to allow playback to
   *     begin in parallel with key acquisition. This parameter specifies whether the renderer is
   *     permitted to play clear regions of encrypted media files before {@code drmSessionManager}
   *     has obtained the keys necessary to decrypt encrypted regions of the media.
   * @param eventHandler A handler to use when delivering events to {@code eventListener}. May be
   *     null if delivery of events is not required.
   * @param eventListener A listener of events. May be null if delivery of events is not required.
   * @param maxDroppedFramesToNotify The maximum number of frames that can be dropped between
   *     invocations of {@link VideoRendererEventListener#onDroppedFrames(int, long)}.
   */
  public MediaCodecVideoRenderer(Context context, MediaCodecSelector mediaCodecSelector,
      long allowedJoiningTimeMs,
      @Nullable DrmSessionManager<FrameworkMediaCrypto> drmSessionManager,
      boolean playClearSamplesWithoutKeys, @Nullable Handler eventHandler, /* event handler create that will decide processing threads */
      @Nullable VideoRendererEventListener eventListener, int maxDroppedFramesToNotify) {
    super(C.TRACK_TYPE_VIDEO, mediaCodecSelector, drmSessionManager, playClearSamplesWithoutKeys);
    this.allowedJoiningTimeMs = allowedJoiningTimeMs;
    this.maxDroppedFramesToNotify = maxDroppedFramesToNotify;
    this.context = context.getApplicationContext();
    frameReleaseTimeHelper = new VideoFrameReleaseTimeHelper(context);
    eventDispatcher = new EventDispatcher(eventHandler, eventListener);
    deviceNeedsAutoFrcWorkaround = deviceNeedsAutoFrcWorkaround();
    pendingOutputStreamOffsetsUs = new long[MAX_PENDING_OUTPUT_STREAM_OFFSET_COUNT];
    pendingOutputStreamSwitchTimesUs = new long[MAX_PENDING_OUTPUT_STREAM_OFFSET_COUNT];
    outputStreamOffsetUs = C.TIME_UNSET;
    lastInputTimeUs = C.TIME_UNSET;
    joiningDeadlineMs = C.TIME_UNSET;
    currentWidth = Format.NO_VALUE;
    currentHeight = Format.NO_VALUE;
    currentPixelWidthHeightRatio = Format.NO_VALUE;
    pendingPixelWidthHeightRatio = Format.NO_VALUE;
    scalingMode = C.VIDEO_SCALING_MODE_DEFAULT;
    clearReportedVideoSize();
  }

```

- 不過在理解了ExoPlayer的大概結構之後，相信為何需要這個Handler的原因大家應該都能理解了。


```info
ExoPlayer本身就是利用handler進行事件分發，和自身的狀態控制，任何用戶的操作，
在ExoPlayer內部的實現都是會變成一個handler能處理的Message，再根據message的內容，
ExoPlayer會讓不同的構件進行相應的操作，再根據操作的結果發下一個消息。
```


## part6 Android DRM content protection(EXO prepare MediaResource)
- DRM platform
    - Widevine
    - PlayReady
    - Adobe Primetime
    - Apple FairPlay

- How does DRM work?


- MediaCodec API with DRM
    - 在這個官方文檔裡面已經講的很詳細了，如果使用`MediaCodec`進行decode的時候,configure()方法需要傳進一個`MediaCrypto`

```C++
configure (MediaFormat format,
                Surface surface,
                MediaCrypto crypto,
                int flags)

crypto | MediaCrypto: Specify a crypto object to facilitate secure decryption of the media data, Pass null as crypto for non-secure codecs.

```

- MediaCodec的drm處理文檔比較齊全，所以問題不大，具體源碼還是又不懂的可以參考ExoPlayer的代碼，`StreamingDrmSessionManager.java裡面整個流程都有。
    - 1.create MediaDrm並且調用其openSession方法，該方法會返回一個sessionID，標識該次解碼工作。
    - 2.create MediaCrypto給MediaCodec 。 它需要一個UUID和initdata，UUID是Widevine的Scheme ID，在Exoplayer的源碼中可以看到,在C.java裡面。而initData就是上面說到的sessionID.
    - 3.對license server做license的call，得到的reponse就是我們需要的license了，此時只需要調用MediaDrm的provideKeyResponse()方法，視頻就可以自動開始播放了。
    - 4.conclusion: MediaCodec負責解碼，
           - 需要一個MediaCrypto, 獲取MediaDrm對的sessionId讓framework去尋找對應的license
           - 需要一個MediaDrm，負責保存從服務器下載下來的license並且提供一個唯一的sessionId給MediaCrypto.

```C++
public static final UUID WIDEVINE_UUID = new UUID(0xEDEF8BA979D64ACEL, 0xA3C827DCD51D21EDL);

// Get sessionId
MediaDrm mediaDrm = new MediaDrm();
String sessionId = mediaDrm.openSession();

// Create MediaCrypto
/**
sessionId 是串聯 MediaDrm和MediaCrypto的關鍵
**/
MediaCrypto ctypto = new MediaCrypto(WIDEVINE_UUID, sessionId)

//用cypto對象來進行解密
MediaCodec codec = new MediaCodec("xxxx")
codec.configure(..,...,ctypto)

/**
注意的是license並不需要在configure之前獲取，可以稍後再進行
**/

//網絡連接
byte[] license = HttpUrlConnection.connect().......
mediaDrm.provideKeyResponse(xxx,license);

/**
所有工作結束，視頻可以正常播放了。
**/

```

## Previous version(Discard)
- Using the DRM API
    - In a typical DRM session, an Android application uses the DRM framework API to instantiate a DrmManagerClient. The application calls various methods on the DRM client to query rights and perform other DRM-related tasks. Each DrmManagerClient instance has its own unique ID, so the DRM manager is able to differentiate callers.

    - Although each DRM plug-in may require a different sequence of API calls, the general call sequence for an application is as follows:

         - Register the device with an online DRM service.
         - You can do this by first using the acquireDrmInfo() method to acquire the registration information, and then using the processDrmInfo() method to process the registration information.

         - Acquire the license that's associated with the rights-protected content.
         - You can do this by first using the acquireDrmInfo() method to acquire the license information, and then using the processDrmInfo() method to process the license information. You can also use the acquireRights() method.

         - Extract constraint information from the license.
         - You can use the getConstraints() method to do this.

         - Associate the rights-protected content with its license.
         - You can use the saveRights() method to do this.

    - After you make an association between the rights-protected content and its license, the DRM manager automatically handles rights management for that content. Specifically, the DRM manager will handle all further licensing checks when you attempt to play the content using the __MediaPlayer__ API.

    - To learn how to use the DRM API with a specific DRM plug-in, see the documentation provided by the plug-in developer.

```C++
// Now this is older version
public static final String WV_DRM_SERVER_KEY = "WVDRMServerKey";
public static final String WV_ASSET_URI_KEY = "WVAssetURIKey";
public static final String WV_DEVICE_ID_KEY = "WVDeviceIDKey";
public static final String WV_PORTAL_KEY = "WVPortalKey";


/**
調用該方法進行解密，執行成功就ok了
**/

  public  void acquireKey(){
        DrmInfoRequest drmInfoRequest = createDrmInfoRequest(assetUrl, infoHolder.getDrmLisenceUrl());
        DrmInfo drmInfo = mDrmManager.acquireDrmInfo(drmInfoRequest);
        int rights = mDrmManager.acquireRights(drmInfoRequest);
    }

  /**
  licenseServerUri 就是 對license server進行http通信的Url
  **/

   private DrmInfoRequest createDrmInfoRequest(String assetUri, String licenseServerUri) {
        DrmInfoRequest rightsAcquisitionInfo;
        rightsAcquisitionInfo = new DrmInfoRequest(DrmInfoRequest.TYPE_RIGHTS_ACQUISITION_INFO,
                WIDEVINE_MIME_TYPE);

        if (licenseServerUri != null) {
            rightsAcquisitionInfo.put(WV_DRM_SERVER_KEY, licenseServerUri);
        }
        rightsAcquisitionInfo.put(WV_ASSET_URI_KEY, assetUri);
        rightsAcquisitionInfo.put(WV_DEVICE_ID_KEY, mDeviceId);
        rightsAcquisitionInfo.put(WV_PORTAL_KEY, PORTAL_NAME);

        return rightsAcquisitionInfo;
    }

```


## Reference
- Android視頻開發進階(part1-關於視頻的那些術語)
    - https://www.jianshu.com/p/10e357946447

- Android視頻開發進階(part2-MP4文件的解析)
    - https://www.jianshu.com/p/2b85c9bc3a12

- Android视频开发进阶(part3-Android的Media API)
    - https://www.jianshu.com/p/667d69eec40c

- Android视频开发进阶(part4-自适应视频播放技术(Adaptive Streaming))
    - https://www.jianshu.com/p/eea65d04b1a3

- Android視頻開發進階(part5-ExoPlayer分析1，ExoPlayer的handler)
    - https://www.jianshu.com/p/5ebdc9bc4f4b

- Android視頻開發進階(part6-安卓的DRM,視頻版權保護)
    - https://www.jianshu.com/p/5a0fb2dedabf
