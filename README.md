# LeetcodeForCpp
利用 leetcode 來複習 C++，利用函式名稱來區分各題解答

leetcode_for_cpp.cpp 為程式進入點，包含 main() 函式。

Solution 類別定義問題的解法。

Tester 類別用來測試 Solution 的解法是否正確與時間花費測試，會包含範本題目與出錯時的問題，若題目過長可能透過讀檔等方式來讀取亦或
直接不放入。


## 暫時筆記處

- 陣列透過函式傳遞時，是以指標的形式傳遞，因此無法透過函式來獲取陣列長度。

- 目前實驗結果，無法透過 vector<T> 的形式在其他腳本接收各種變數型態的 vector ，給予實際的變數型態後可正常運作。

- map 也和上面一點相同。 

- 上述兩點，可先以擁有實際變數型態的函式來接收，讓該腳本知道實際上的變數型態，再呼叫 <T> 達到只寫一次內容的效果，但目前的做法需要
對不同變數都設置一組函式，只是內部不需要重複實作而已。