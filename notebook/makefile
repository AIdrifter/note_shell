# makefile
# 遞迴
給visual c++用的

# 如何寫作makefile
在Unix系統上編譯tarball時，通常需要三步驟：
./configure
make
make install
這中間的make指令便是利用makefile來處理編譯步驟。
Makefile的概念非常像是批次檔，但是它有更強大的能力。
make會查閱每一步驟所需要的檔案，如果沒有便執行指令以產生該檔案，如果已經是最新狀態，就直接跳到下個步驟。撰寫者只要了解原始碼的編譯步驟，就可以依序寫好指令，如此只要有Makefile，不管是誰只要鍵入make就可以成功編譯出檔案。
以最簡單的單一檔案來說，編譯指令應該如下：
gcc helloworld.c -o helloworld
這樣會把helloworld.c編譯為helloworld這個執行檔。
而若要寫為makefile，可以這麼寫：
all: helloworld
        gcc helloworld.c -o helloworld
        檔名存為Makefile或是makefile都可以[?]，這就是最簡單的makefile。
        上面的意義為，要完成all這個目標，需要helloworld這個檔案，如果找不到它，就執行gcc helloworld.c -o helloworld這個指令。
        注意，all是個關鍵字，良好的makefile都要有一個all，因為這是預設執行目標。
        且一定要用tab縮排，否則它不會認目標底下的指令。換行符號也請用Unix的換行符。
        若是要編譯多個檔案呢？比方說現在有三個檔案：application.c, interface.h, implementation.c，application.c引用了interface.h的函式，而implementation.c則是interface.h的實作。
        先來看一下平常編譯該怎麼編：
        gcc -c application.c
        gcc -c implementation.c
        gcc implementation.o application.o -o result
        這樣編譯出來的result就是可執行檔。
        所以來整理一下：result檔需要implementation.o和application.o這兩個檔案，而這兩個檔案分別需要implementation.c和application.c，如此一來就會變成：
all: result
        result: implementation.o application.o
        gcc implementation.o application.o -o result
implementation.o: implementation.c
        gcc -c implementation.c
application.o: application.c
        gcc -c application.c
        意即：欲完成all需要先完成result目標，欲完成result需要先完成implementation.o和application.o這兩個目標，而要達成implementation.o和application.o則分別需要implementation.c和application.c這兩個檔案。
        你也可以選擇只執行其中一個目標，像是make application.o就只會產生application.o檔。
        總而言之，makefile的基本型式是：
target: required file or target
        commands to complete this target
        底下不限定有多少行指令，只要有用tab縮排即可。
        而且目標也不一定要有前置目標，如果執行的目標沒有前置目標的話，代表目標底下的命令一定會執行。
        如果你覺得太長，想省略一點，也可以用萬用符號[?]：
all: result
        result: *.o
        gcc *.o -o result
*.o: *.c
        gcc -c *.c
        這個版本可以跟上面的版本達到相同的效果，不過當然有點危險就是了。
        當然不只能用來編譯，也許你會希望能夠有清掉過程檔的功能：
all: result clean
        result: *.o
        gcc *.o -o result


*.o: *.c                                                                                                                                                                                                                                                              [75/7940]
        gcc -c *.c
clean:
        rm -f *.o
        這樣在下完make之後會立刻把所有的.o檔清除，或是也可以用make clean除掉。
        也許你在編譯完成之後都會執行一次該程式來測試，那麼也可以這麼寫：
all: result clean
        result: *.o
        gcc *.o -o result
*.o: *.c
        gcc -c *.c
clean:
        rm -f *.o
test: result input.txt
        ./result 如此只要輸入make test就會自動執行測試。
        當找不到input.txt時，make會自動停止並回報錯誤，因為文件中找不到如何生成input.txt的資訊。
        儘管make沒有明定什麼目標該做什麼事，但是在約定成俗的目標上，請按照慣例：
        make all要用來生成所有程式。
        make install要用來安裝程式。
        make clean要用來清除暫時檔。
        其他經常用的目標也請不要逆天。
        當然這只是最最簡單的makefile，其他如關鍵字聲明之類的，可以去翻make的文件；而automake這套程式可以幫助你生成大型專案的makefile。



目標(target)

簡介

目標可以是檔名或者是一個代表動作的識別符號，如果不是檔名的Target叫 phony target。make根據指定的target來做相關動作。

要完成一個目標前會先檢查他所需要的檔案或要先做的phnoy target，即 相依性檔案或先決條件目標(dependency or prerequiste) 如果要的相依或先決目標不存在，則make會失敗。如果這裡的先決目標是 phony target則PHONY TARGET每次都會被執行。

如果你在shell prompt只下make命令而已，第一個rule永遠被執行。 這叫default goal。如果你有指定target名字，例如make clean，則會 去執行這個target的動作，以上面例子看就是會執行 rm *.o *~ 這個動作。

一些目標規定

有些phony目標是GNU建議的，不見得一定要有啦只是建議目標。例如
all     :內定的編譯動作
        install :安裝binary檔的動作
clean   :清除obj檔的動作
        dist    :產生configure的動作
distclean       :清除configure所產生的檔

特別的內定目標(built-in target)

有些目標名稱已經有特別規定了，例如

一些內定目標

.PHONY:
        在這個後面的target無條件執行。因為例如
clean:
        rm *.o

如果萬一真的有一個叫clean的檔案在make的目錄下， 偏偏這個檔沒有update，日期沒變，所以當你make clean時， make認為這個clean已經有了，也沒有相依性檔案需要重新編譯， 於是就不執行rm *.o了 。 所以我們要把它寫在.PHONY，則每次make clean就無條件執行， 不會把clean看成是檔名。

.SUFFIXS:
        make有一些內定方法編譯特別副檔名，這些副檔名規則的副檔名 (名單)list，是在SUFFIXS這個變數裡， 可能有.c .o .cpp 等等。 用
.SUFFIXS:

清掉內定副檔名list。 用
.SUFFIXS: .sgml .hack

加上.sgml .hack到內定list。

.SILENT:
        這裡面的target執行時 命令(command)將不會印出來

. -lXPORT_ALL_VARIABLES:
        把所有變數告訴後來sub shell的子程序

內隱規則(Implicit Rules)


.c 編成foo.o。像這樣的編譯習慣，gnu make有一些內定規則來編譯， 也就是有的target你不寫，make也可以根據內定規則把他編譯出來。不用 對每個不同的.o寫不同的規則， 如果有個程式由foo.c foo1.c foo2.c......寫這些就
寫得會發瘋了，例如
foo.o:foo.c
        gcc -c -o foo.o foo.c
foo1.o:foo1.c
        gcc -c -o foo1.o foo1.c
        ....

因此 如果你不寫foo.o的規則，那麼make當別的規則用到foo.o時，他找不到規則 來編，就會自動找foo.c來編譯。這樣看不到的編譯規則有很多，如
C程式
$(CC) -c $(CPPFLAGS) $(CFLAGS) xxx.c來編譯
或者找不到.c時會去找.cc, .cpp, .C檔

C++程式
$(CXX) -c $(CPPFLAGS) xxx.cpp

TeX
xxx.dvi 由xxx.tex產生

Pascal
$(PC) -c $(PFLAGS) xxx.p

自己的內隱規則

因為可能有的時候你希望做些dependency檢查，或者加上一些gcc 用的旗標，不是很單純的編譯而已你可以給make自訂的內隱規則

自訂規則

樣式規則(pattern rule)
你可以用pattern rule來做一些自定的內隱規則。像這樣
%.o : %.c prog.h
        $(CC) $(CFLAGS) $(DEBUG_FLAG) -c -o $@ $<

或者
%.pdf : %.sgml
        db2pdf $<

%表示所有相對於後面先決條件的檔名的意思，他不是*，因為他 有一對一的相對應關係，foo.o 就要找foo.c，foo1.o就要找foo1.c， 所以他不是*。所以上面的意思是所有碰到要.o的target時，去找相 對應的.c檔，並根據先決條件prog.h做檢查，如果找不到prog.h就不 做下去了。%不只可以表現主檔名，
其實可以表現任一個相對應的字串， 所以叫pattern，你可以用s.%.c，不只用&.c，其中對應到%的子字 串叫stem。另外$@ $<...這種符號，叫自動變數，請往後翻一下， 看一下解說。

pattern rule也可以有特定變數設值，特定樣式(pattern)的變數，例如
%.o : CFLAGS = -O

表示只要有要編譯xxxx.o的規則時，通通要設CFLAGS為-O。

副檔名規則
還有更古老的一種叫suffix rule的方法來做，這種方法就有限制性 了，因為只能用在副檔名的規則。例如
.c.o:
        $(CC) -c -o $*.o $<
.S.o:
        $(CC) -c -o $*.o $<

小心喔，跟%o : %c順序不一樣喔

自動變數與內隱規則

因為這樣動態的編譯手法，它需要像在CVS裡面的%v %V %s這種東西來代替一些 動態改變的字串(幫你複習一下CVS)。所以有所謂的自動變數
$@      同一個規則的目標名
$*      這個只有在內隱規則中有用。表示樣式或副檔名規則中對應到的字串。
$<      同一規則的第一個先決條件名，這個大部分用在suffix rule，因為
suffix rule只有一個檔。
$?      同一個規則的所有先決條件名，但是只有原始程式碼改過的比obj檔新才會
符合，也就是比target還新的先決條件檔案。
$^ 所有先決條件，但是有的make像solaris make可能不認得這個自動變數。

上面是比較常用的
簡介                                                                                                                                                                                                                                                                   [1/7940]

通常我們編譯程式時有很多算是每個人都有的共同習慣，例如我就是把 foo.c 編成foo.o。像這樣的編譯習慣，gnu make有一些內定規則來編譯， 也就是有的target你不寫，make也可以根據內定規則把他編譯出來。不用 對每個不同的.o寫不同的規則， 如果有個程式由foo.c foo1.c foo2.c......寫這些就
寫得會發瘋了，例如
foo.o:foo.c
        gcc -c -o foo.o foo.c
foo1.o:foo1.c
        gcc -c -o foo1.o foo1.c
        ....

因此 如果你不寫foo.o的規則，那麼make當別的規則用到foo.o時，他找不到規則 來編，就會自動找foo.c來編譯。這樣看不到的編譯規則有很多，如
C程式
$(CC) -c $(CPPFLAGS) $(CFLAGS) xxx.c來編譯
或者找不到.c時會去找.cc, .cpp, .C檔

C++程式
$(CXX) -c $(CPPFLAGS) xxx.cpp

TeX
xxx.dvi 由xxx.tex產生

Pascal
$(PC) -c $(PFLAGS) xxx.p

自己的內隱規則

因為可能有的時候你希望做些dependency檢查，或者加上一些gcc 用的旗標，不是很單純的編譯而已你可以給make自訂的內隱規則

自訂規則

樣式規則(pattern rule)
你可以用pattern rule來做一些自定的內隱規則。像這樣
%.o : %.c prog.h
        $(CC) $(CFLAGS) $(DEBUG_FLAG) -c -o $@ $<

或者
%.pdf : %.sgml
        db2pdf $<

%表示所有相對於後面先決條件的檔名的意思，他不是*，因為他 有一對一的相對應關係，foo.o 就要找foo.c，foo1.o就要找foo1.c， 所以他不是*。所以上面的意思是所有碰到要.o的target時，去找相 對應的.c檔，並根據先決條件prog.h做檢查，如果找不到prog.h就不 做下去了。%不只可以表現主檔名，
其實可以表現任一個相對應的字串， 所以叫pattern，你可以用s.%.c，不只用&.c，其中對應到%的子字 串叫stem。另外$@ $<...這種符號，叫自動變數，請往後翻一下， 看一下解說。

pattern rule也可以有特定變數設值，特定樣式(pattern)的變數，例如
%.o : CFLAGS = -O

表示只要有要編譯xxxx.o的規則時，通通要設CFLAGS為-O。

副檔名規則
還有更古老的一種叫suffix rule的方法來做，這種方法就有限制性 了，因為只能用在副檔名的規則。例如
.c.o:
        $(CC) -c -o $*.o $<
.S.o:
        $(CC) -c -o $*.o $<

小心喔，跟%o : %c順序不一樣喔

自動變數與內隱規則

因為這樣動態的編譯手法，它需要像在CVS裡面的%v %V %s這種東西來代替一些 動態改變的字串(幫你複習一下CVS)。所以有所謂的自動變數
$@      同一個規則的目標名
$*      這個只有在內隱規則中有用。表示樣式或副檔名規則中對應到的字串。
$<      同一規則的第一個先決條件名，這個大部分用在suffix rule，因為
suffix rule只有一個檔。
$?      同一個規則的所有先決條件名，但是只有原始程式碼改過的比obj檔新才會
符合，也就是比target還新的先決條件檔案。
$^ 所有先決條件，但是有的make像solaris make可能不認得這個自動變數。

上面是比較常用的

內隱規則內也預設了一些變數，例如
AR = ar
CC = cc
MAKE = make
CXX = g++

If you don't have CC 變數，則自動是cc這個值，可以直接拿$(CC)來用。 自定內隱規則可以寫在任何地方，make會自動先找到他們，等到要用時就會 去用。通常在一些系統上例如Solaris, AIX...已經有Sun IBM的make了， 所以系統管理者通常會把GNU make叫gmake，這時可以設MAKE = gmake。

# cast string
# Makefile Rule

# Cast string to integer
# Support version > 5.0
RH_VER_MAJOR := $(shell echo $(NFX_VERSION) | cut -f1 -d.)
NFX_VERSION_RATHER_50 := $(shell [ $(RH_VER_MAJOR) -gt 50 -o \( $(RH_VER_MAJOR) -eq 50 \) ] && echo true)
ifeq ($(NFX_VERSION_RATHER_50),true)
PLAYREADY_30_ENABLE=1
endif

