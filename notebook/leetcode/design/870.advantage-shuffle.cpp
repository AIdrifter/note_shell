/*
 * @lc app=leetcode id=870 lang=cpp
 *
 * [870] Advantage Shuffle
 *
 * https://leetcode.com/problems/advantage-shuffle/description/
 *
 * algorithms
 * Medium (41.08%)
 * Total Accepted:    8.6K
 * Total Submissions: 20.8K
 * Testcase Example:  '[2,7,11,15]\n[1,10,4,11]'
 *
 * Given two arrays A and B of equal size, the advantage of A with respect to B
 * is the number of indices i for which A[i] > B[i].
 *
 * Return any permutation of A that maximizes its advantage with respect to
 * B.
 *
 *
 *
 *
 * Example 1:
 *
 *
 * Input: A = [2,7,11,15], B = [1,10,4,11]
 * Output: [2,11,7,15]
 *
 *
 *
 * Example 2:
 *
 *
 * Input: A = [12,24,8,32], B = [13,25,32,11]
 * Output: [24,32,8,12]
 *
 *
 *
 *
 * Note:
 *
 *
 * 1 <= A.length = B.length <= 10000
 * 0 <= A[i] <= 10^9
 * 0 <= B[i] <= 10^9
 *
 *
 *
 *
 */
class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
#if 1
       multiset<int> SortedA(A.begin(),A.end());
       vector<int> ans;

       for(int i=0;i<B.size();i++)
       {
            auto iter = SortedA.upper_bound(B[i]);

            if (iter == SortedA.end())
                iter = SortedA.begin();

            ans.push_back(*iter);
            SortedA.erase(iter);
       }

       return ans;
    }
#else
    /*
     *     Solution: Greedy 田忌赛马
     *     Use the smallest unused number A[j] in A such that A[j] > B[i],
     *     if not possible, use the smallest number in A.
     */
    //  [Study]
    //  set and multiset 會根據特定的排序準則，自動將元素進行排序。不同的是後者允許元素重複而前者不允許。
    //
    multiset<int> s(begin(A), end(A));
    vector<int> ans;
    for (int b : B) {
      // [Study]
      //  1.auto : https://blog.gtwang.org/programming/cpp-auto-variable-tutorial/
      //  2.multitest
      //     a.upper_bound()
      //       Returns an iterator pointing to the first element in the range [first,last) which compares greater than val.
      //     b.erase()
      //        remove iterator pointing the element from mulitest
      auto it = s.upper_bound(b);
      if (it == s.end())
            it = s.begin(); // 都贏不了 就準備拿最弱的(數字最小) 對抗b[i]

      ans.push_back(*it);
      s.erase(it);
    }
    return ans;
  }

#endif
};


// C++ 98
std::vector<int>& addOneC98(std::vector<int> &v) {
  for(std::vector<int>::iterator it = v.begin(); it != v.end(); it++) {
    *it += 1;
  }
  return v;
}


// C++ 11
std::vector<int>& addOneC11(std::vector<int> &v) {
  for(auto& it : v) {
    it += 1;
  }
  return v;
}

// C++ 14
auto& addOneC14(std::vector<int> &v) {
  for(auto& it : v) {
    it += 1;
  }
  return v;
}
