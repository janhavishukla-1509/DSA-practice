class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int piv = -1; int n = A.size();
        for(int i = n - 2; i >= 0; i --){
            if(A[i] < A[i+1]){
                piv = i;
                break;
            }
        }
            if(piv == -1){
                reverse(A.begin(), A.end());
                return;
            }
            for(int i = n - 1; i > piv; i --){
                if(A[i] > A[piv]){
                    swap(A[i], A[piv]);
                    break;
                }
            }
                int k = piv + 1, j = n -1;
                while( k <= j){
                    swap(A[k++], A[j--]);
                }
            //directly can use : next_permutation(A.begin(), A.end());
        
        
    }
};