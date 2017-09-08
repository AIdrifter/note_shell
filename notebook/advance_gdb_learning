# advance gdb learning
arm-none-linux-gnueabi-objdump -d xxxxx.o
00000000 <_GLOBAL__sub_I_sAPI__lsc.cpp>:
   0:   e92d4800        push    {fp, lr}
   4:   e28db004        add     fp, sp, #4

arm-none-linux-gnueabi-addr2line -e symbols/applications/bin/fk_board 0x41018b40
arm-none-linux-gnueabi-addr2line -e symbols/applications/bin/fkos 0x69115c

arm-none-linux-gnueabi-addr2line -e libutopia.so 0xf55dabc8 0xf5518bc8

arm-none-linux-gnueabi-addr2line -e libstagefright_omx.so 00013c60

arm-none-linux-gnueabi-gdb ./tsbui/Apps/TsbAppMgr/EU/bin/QQQQ_board
arm-none-linux-gnueabi-gdb symbols/applications/bin/QQQQ_board
arm-none-linux-gnueabi-gdb symbols/applications/bin/fkos
arm-none-linux-gnueabi-gdb symbols/applications/bin/fk_board
arm-none-linux-gnueabi-readelf

armv7a-cros-linux-gnueabi-gdb symbols/applications/bin/
mips-linux-gnueabi-gdb symbols/applications/bin/QQQQ_board
mips-linux-gnu-gdb symbols/applications/bin/QQQQ_lite_board
/tools/mips-4.3-51/mips-4.3/bin/mips-linux-gnu-gdb symbols/applications/bin/QQQQ2_board
set solib-absolute-prefix ./symbols/
handle SIGTSTP nostop noprint
handle SIGSTOP nostop noprint
handle SIG38 nostop noprint
target remote x.xx.xx.xx:5678
core Coredump
thread apply all bt
p *(pthread_mutex_t*)
break API__cc.cpp:_HANDLESTRUCT::Cc::FeatureConnect
break API__cc_rx.cpp:CcRx::SetCcVersion
break api_rec_demux.cpp:api_rec_demux::AddRecordPID
break api_demux.cpp:api_demux::PKDscmbConnect
break api_audio_customer.cpp:api_audio_customer::SetSoundMuteStatus
break MW_DTV_AVMonitor.cpp:MW_DTV_AVMonitor::SetMuteFlag if (bMute == true)
break rv_MMI.cpp:rv_MMI::Init
break MW_DTV_EPG_DVB_PARSER.cpp:MW_DTV_EPG_DVB_PARSER::_EIT_Parser_Cb:1047 if (u16TS == 0x302)

set solib-absolute-prefix ./symbols/
handle SIGTSTP nostop noprint
handle SIGSTOP nostop noprint
handle SIG38 nostop noprint
target remote 172.16.58.42:5678
break rv__Adaptation.cpp:Adaptation::IsInCuProgress
p aEvent.m_pShortEventDescriptor
watch ((rv_DTV_Player_DVB *)0x1eeb600)->m_bInit
set solib-absolute-prefix ./symbols/

break apiDMX.c:_api_DMX_AVFifo_Reset if ((DmxFltType == 1)&&(bReset == 1))
break PK_Path_Upload.cpp:PK_Path_Upload::ResumeAudioOutput
break apiDMX.c:api_DMX_AVFifo_Reset
break api_storage.cpp:api_storage::_Write
break api_storage.cpp:512
watch this->m_bInit
break
kill -9 `pidof dial`
kill -9 `pidof mongoose`
