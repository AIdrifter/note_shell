# Sinfleton Pattern
- 實現單例模式的思路是：一個類別只有一個實例，並提供全域點存取此實例。
    - 設定和登入的物件
    - 驅動程式溝通的物件
    - Thread pool執行緒池等

- Be careful to multi thread situation
    - 1.對`situatiotance()`這個函式同步化，不過會造成程式執行效率降低，如果需要頻繁運作此函式，可能需要重新考慮。
    - 2.**率先建立實例**，而不用拖延實體化的作法，如以下所示：

```C++
class Singleton {
private:
    // create instance firstly
    static Singleton *m_instance = new Singleton();
    Singleton(){}
public:
    static Singleton *getInstance(){
        return m_instance;
    }
};
```
- 3.利用**雙重檢查上鎖**，在`getInstance()`中減少使用同步化，檢查實例是否已經建立，沒建立的話才進行同步化，如此一來只有第一次會同步化，如以下所示：
> 大神 : 沒有屁用?? 我在google看看

```C++
class Singleton {
private:
    //volatile不會對m_instance進行編譯器最佳化，確保多執行緒處理m_instance是正確的
    volatile static Singleton *m_instance;
    Singleton(){}
public:
    static Singleton *getInstance(){
        if(m_instance==NULL){
            //下面進行同步化
            m_instance = new Singleton();
        }
        return m_instance;
    }
};
```

