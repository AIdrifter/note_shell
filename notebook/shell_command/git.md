# git
git checkout .
git pull --rebase
git branch -av
git checkout origin/master
git pull --rebase
git branch -av
git push origin HEAD:refs/for/marshmallow


# cherry pick
1.可已合到別的分支
2.還是要被merge才會進去

# git reset vs git revert
git reset $SHA_VALUE
git reset HEAD^ --soft # 修改保留
git reset HEAD^ --hard

# git check out 某tag
先利用 git clone 抓取整個repository
再利用 git tag -l 列出全部的tag清單
最後用 git checkout --track <tag_name>


# git 打tag
git tag -a TAG-02.76.20160226 <commit id> -m 'Release library(LIB-02.76.20160226)'
git push origin TAG-02.79.20160505
git push origin --tags

# before git add
git config core.fileMode false

# repo sync
repo init -u ssh://git:30000/manifest/main -b tvos --depth=1 # git log 深度
repo sync

# cherry pick
merge some CL to your branch
Download(right up corrner)->cherry pick

                        除非有confilt 的問題
                        若有confilt 就要到server 上修正
                        Command example
                                先切到tvos
                                git cherry-pick –x 65cce13cdba84010ad (commit-id)
                                git status (看哪一個檔造成confilt)
                                git add file name
                                git cherry-pick --continue
                                git push origin HEAD:refs/for/master


# How can I list all tags in my Git repository by the date they were created?
git for-each-ref --sort=taggerdate --format '%(refname) %(taggerdate)' refs/tags

git checkout 3f4ae60b5cb70f356048b6f992cba5767453a44d -- MStarSDK/src/system/mapi_system.cpp


# git push refuse...
git pull --rebase
git stash
git push

# git rebase to resolve comflict
git rebase origin/master

# git tracking
git checkout -b snr origin/snr
git co snr
git checkout snr
git pull

# tig
tig
jk move

#  ! [remote rejected] HEAD -> refs/for/master (change http://hcgit03:8080/169176 closed)
# error: failed to push some refs to
 git pull --rebase
 git push origin HEAD:refs/for/master

# ox awsome
tig blame/ git blame
tig   +  jk等方向鍵

# git revrt file mode
git diff -p | grep -E '^(diff|old mode|new mode)' | sed -e 's/^old/NEW/;s/^new/old/;s/^NEW/new/' | git apply
