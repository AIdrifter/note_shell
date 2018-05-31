public static final UUID WIDEVINE_UUID = new UUID(0xEDEF8BA979D64ACEL, 0xA3C827DCD51D21EDL);

/* Get sessionId */
MediaDrm mediaDrm = new MediaDrm(WIDEVINE_UUID);
String sessionId = mediaDrm.openSession();

/*
* Create MediaCrypto
* sessionId 是串聯 MediaDrm和MediaCrypto的關鍵
*/
MediaCrypto ctypto = new MediaCrypto(WIDEVINE_UUID, sessionId);

/* 用cypto來進行解密 */
MediaCodec codec = new MediaCodec("xxxx");
codec.configure(..,...,ctypto);

/*
 *注意的是license並不需要在configure之前獲取，可以稍後再進行
*/

/* network connect */
byte[] license = HttpUrlConnection.connect().......

/*
 * getKeyRequest(byte[] scope, byte[] init, String mimeType,
 * int keyType, HashMap<String, String> optionalParameters)
 * mimeType(container)
 *     smooth streaming  : apllicatiopn X smooth streaming
 *     fragment   mmp4   : .mp4
 *     DASH              : HML, CENC
 * Key type
 *     remove or add
*/
mediaDrm.getKeyRequest(scope, initData, mimeType, keytype,
        optionalKeyRequestParameters);

 /*
  * public byte[] provideKeyResponse(byte[] scope, byte[] response)
  * license response : playready is XML
 */
mediaDrm.provideKeyResponse(xxx,license);

