# secure stop

https://developer.android.com/reference/android/media/MediaDrm.html
主要用途在告知license server同時間有幾個正在運作的device
用以限制同一個account不能無限制的以不同device做收看

Secure Stop provides cryptographic proof that the content key has been securely deleted from memory and the content key can no longer be used to decrypt encrypted media. Netflix uses Secure Stop to accurately count active streams per subscriber account and enforce the nu
mber of concurrent streams authorized for each subscriber account.
Note on Secure Stop: Netflix has enhanced DRM with a Secure Stop implementation that has been blessed by the Microsoft. The modifications for integration of Secure Stop are readily available for you in the form of a patch on the Netflix portal.
Please state whether or not your device supports Secure Stop.

# anti-rollback
EE Protected Storage
重點是如何避免被人以先備份檔案在用蓋檔案的方式做data rollback

主要業界常用手法
RPMB:http://stackoverflow.com/questions/19952000/replay-protected-memory-block-emmc
以硬體方式完全隔絕一般的linux file access
https://github.com/OP-TEE/optee_os/blob/master/CHANGELOG.md
依照文件描述
OP-TEE - version 2.0.0
RPMB support: Secure Storage can now use Replay Protected Memory Block (RPMB) partition of an eMMC device. Check the full documentation

OP-TEE - version 2.1.0
File Storage: Possibility to use the normal world filesystem and the RPMB implementations simultaneously.

總結來說Netfli 的TPS(TEE Protected Storage)只是一個term
要求就是file anti-rollback
而RPMB是實際上用來實作TPS的一種方案


