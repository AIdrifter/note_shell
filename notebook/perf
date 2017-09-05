# perf
http://wiki.csie.ncku.edu.tw/embedded/perf-tutorial

# PMU
PMU (Performance Monitoring Unit
上面介紹的幾種處理器特性對軟體效能影響很大，然而依賴時鐘進行定期採樣的 profiler 模式無法闡述程式對這些處理器硬體特性的使用情況。處理器廠商針對這種情況，在硬體中加入了 PMU (performance monitor unit)。PMU 允許硬體針對某種事件設置 counter，此後處理器便開始統計該事件的發生次數，當發生的次數超過 counter 內設定的數值後，便產生中斷。比如 cache miss 達到某個值後，PMU 便能產生相應的中斷。一旦捕獲這些中斷，便可分析程式對這些硬體特性的使用率了。


#Tracepoints
Tracepoint 是散落在核心原始程式碼的一些 hook，一旦使能，在指定的程式碼被運行時，tracepoint 就會被觸發，這樣的特性可被各種 trace/debug 工具所使用，perf 就是這樣的案例。若你想知道在應用程式執行時期，核心記憶體管理模組的行為，即可透過潛伏在 slab 分配器中的 tracepoint。當核 心運行到這些 tracepoint 時，便會通知 perf。

Perf 將 tracepoint 產生的事件記錄下來，生成報告，通過分析這些報告，效能分析調校的工程人員便可瞭解程式執行時期的核心種種細節，也能做出針對效能更準確的診斷。
=> 無optee kernel 無法測量

# perf 3 function
前面有提到，Perf 能觸發的事件分為三類：

hardware : 由 PMU 產生的事件，比如 cache-misses、cpu-cycles、instructions、branch-misses …等等，通常是當需要瞭解程序對硬體特性的使用情況時會使用。

software : 是核心程式產生的事件，比如 context-switches、page-faults、cpu-clock、cpu-migrations …等等。

tracepoint : 是核心中的靜態 tracepoint 所觸發的事件，這些 tracepoint 用來判斷在程式執行時期，核心的行為細節，比如 slab 記憶體配置器的配置次數等。

