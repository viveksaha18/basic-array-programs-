#include<bits/stdc++.h>
using namespace std;


// Global vector for question 7 
vector<vector<int>> ans; // List of list for storing all the vectors


// Question 1
// Brute Force Approach 
// Time complexity : O(n2) and Space complexity : O(1)
pair<int,int> sumProblembrute(vector<int> &arr){
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            return {i,j};
        }
    }
    return {-1,-1}; // if no one meets the target
}

// Optimal Approach 
// Using hashing as we know we want elements index which sums up to give the target value 
// So our intuition behind this problem is to look for an element = target-arr[i] take the first element as arr[i] if the element is not there then just add the ith index element with their index value 
// The best way for it to use map 
// Time complexity : O(n) and Space complexity : O(n)
pair<int,int> twoSumbetter(vector<int> &arr, int target){
    unordered_map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        int a=arr[i];
        int ele=target-a;
        if(mpp.find(ele)!=mpp.end()){
            return {mpp[ele],i};
        }
        mpp[a]=i;    // The stores the element with the value based on indexing
    }
    return { };
}


// Question 2 
// Brute Force Approach 
// Time complexity : O(n2) and Space complexity : O(1)
int majElebrute(vector<int> &arr){
    int ele=INT_MIN;
    for(int i=0;i<arr.size();i++){
        int cnt=0;
        for(int j=0;j<arr.size();j++){
            if(arr[i]==arr[j]){
                cnt++;
            }
            if(cnt > arr.size()/2){
                ele = arr[i];
                break;
            }
        }
    }
    return ele;
}

// Better Approach 
// Apparently we want occurence of element and it is greater than n/2 the we got the element so we use hashing technique
// Time complexity : O(n log m) and Space complexity : O(n)
void majElebetter(vector<int> &arr){
    map<int,int> mpp;
    for(int i=0;i<arr.size();i++){
        mpp[arr[i]]+=1;
    }
    for(auto it : mpp){
        if(it.second > arr.size()/2){
            cout<<it.first<<endl;      // The key which have occurence of greater than > n/2
            break;
        }
    }
}

// Optimal Approach 
// Moore's Voting Algorithm
// This algo helps us to find the maj element the intuition is very simple consider the first element as maj ele and then iterate over the array if the element in array equals to the maj ele you consider then increament the cnt otherwise decreament the cnt and when the cnt becomes 0 just change your majele 
void majEleoptimal(vector<int> &arr){
    int cnt=0;
    int majele;
    for(int i=0;i<arr.size();i++){
        if(cnt==0){
            cnt=1;
            majele=arr[i];
        }
        else if(majele==arr[i]){
            cnt++;
        }
        else {
            cnt--;
        }
    }
    cnt=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==majele){
            cnt++;
        }
        if(cnt > arr.size()/2){
            cout<<majele;
            break;
        }
    }

}


// Question 3 
// Brute Force Approach 
void maxSubbrute(vector<int> &arr){
    int maxi=INT_MIN;
    int sum;
    for(int i=0;i<arr.size();i++){
        sum=0;
        for(int j=i;j<arr.size();j++){
            sum+=arr[j];
            maxi=max(sum,maxi);
        }
    }
    cout<<maxi<<": The maximum sum of the subarray "<<endl;
}
//Optimal Approach 
//Using kdane's Algorithm
//We know we add a number to a negative it decreases so when the sum becomes less than 0 just update it to zero
void maxSuboptimal(vector<int> &arr){
    int maxi = INT_MIN;
    int sum=0;
    for(int i=0;i<arr.size();i++){
        sum+=arr[i];
        maxi=max(sum,maxi);
        if(sum < 0){
            sum=0;
        }
    }
    cout<<maxi<<endl;
}


// Question 4
void maxScore(vector<int> &arr){
    if(arr.size() < 2){
        cout<<"NO ADJACENT SUM : "<<endl;         // For one element 
    }
    int maxi=INT_MIN;
    int sum=0;
    for(int i=0;i<arr.size()-1;i++){
        sum=arr[i]+arr[i+1];
        maxi=max(maxi,sum);
    }
    cout<<"The largest adjacent is : "<<maxi;
}


// Question 5
//Brute Force Approach 
//Time Complexity : O(2n) and Space Complexity : O(1)
void stock_buy_sellBrute(vector<int> &arr){
    int buy = INT_MAX;
    // This will give the minimal value to buy the stock 
    for(int i=0;i<arr.size();i++){
        buy=min(buy,arr[i]);
    }
    // For Calculating profit if have to do arr[i] - buy which element gives maximum output is  my profit 
    
    int profit = 0;
    // buy on day 2 cannot sell on day 1st so we have to start from the day of buying the stock 
    for(int i=buy;i<arr.size();i++){
        profit=max(profit,arr[i] - buy );
    }
    cout<<"The profit : "<<profit<<endl;
}
//Optimal Approach 
//Hypothetically buy the stock at first day and starts iteration of the loop from 1 and then profit by arr[i] - buy and then found their minimum arr[i] and buy 
//Time Complexity : O(n) and Space Complexity : O(1)
void stock_buy_sellOptimal(vector<int> &arr){
    // Buy the stock at the day first 
    int buy = arr[0];
    //Take profit as zero as no one wants negative profit
    int profit = 0;
    // Starts iteration form 1
    for(int i=1;i<arr.size();i++){
        profit = max(profit , arr[i] - buy);
        buy=min(buy,arr[i]); // keep updating buy as if next day the stock decrease we should buy on that day which give us maximum profit
    }
    cout<<"The profit : "<<profit<<endl;
}


// Question 6 
// Brute Force Approch 
/*Intuition : We use two arrays namely as pos and neg in pos array positive where stored and in neg array negative where stores 
After that we arrange pos array elements in arr[2*i] position as all the postitive element in the even index in the given array and neg array elements in arr[2*i+1] position in odd position 
*/
// Time Complexity : O(2n) and Space Complexity : O(n)
void rearrange_Brute(vector<int> &arr){
    vector<int> pos;  // Stores positive elements 
    vector<int> neg;  // Stores negative elements 
    for(int i =0;i<arr.size();i++){
        if(arr[i]  > 0){
            pos.push_back(arr[i]);
        }
        else{
            neg.push_back(arr[i]);
        }
    }
    // Now arranging them 
    for(int i=0;i<arr.size()/2;i++){
        arr[2*i] = pos[i];
        arr[2*i+1] = neg[i];
    }
    // After arranging the array will look like 
    for(auto it : arr){
        cout<<it<<" ";
    }
    cout<<endl;
}
// Optimal Approach 
/*Intuition : We know all the positive numbers will appear in positive Index and the negatives appears in odd Index . So we use two pointer
appraoch in which points on negative and positive indexes */
void rearrange_Optimal(vector<int> &arr){
    vector<int> ans; // Stores the rearranged elements 
    int even_Index =0; // for positives 
    int odd_Index =1; // for(negatives)
    for(int i=0;i<arr.size();i++){
        if(arr[i] > 0){
            ans.push_back(arr[even_Index]);
            even_Index+=2; // Incremented by 2 for the next position of the positives
        }
        else{
            ans.push_back(arr[odd_Index]);
            odd_Index+=2;   // Incremented by 2 for the next position of the negatives
        }
    }
    // The ans will look like 
    for(auto it : ans ){
        cout<<it<<" ";
    }
}


// Question 7 
// Brute Force Approach 
// Finds all the permutation and then look for the next permuation
void allpermuation(vector<int> &arr , int i){
    // Global vector is declared in this problem 
    if(i == arr.size() ){
        ans.push_back(arr);
        return;     // Base case at here a found a permutation 
    }
    for(int j = i ; j < arr.size(); j++){
        swap(arr[i] , arr[j]);
        allpermuation(arr,i+1);
        swap(arr[i],arr[j]);
    }
}

// Better Approach 
// Using STL 
void nextpermutation_better(vector<int> &arr){
    bool hasNext = next_permutation(arr.begin() , arr.end());
    if(hasNext){
        for(auto it : arr){
            cout<<it<<" ";
        }
    }
    else{
        cout<<"NO next permutation is available"<<endl;
    }
}
void nextpermutation_brute(vector<int> &arr){
    allpermuation(arr,0);
    // Linear Search
    // Lets say we are looking for the next permutation after 123
    vector<int> srch = {3,1,2};
    vector<int> temp; // For printing the next permutation 
    for(int i = 0 ; i < ans.size()-1 ; i++){
        if(ans[i] == srch){
            temp = ans[i+1];
            break;
        }
    }
    if(!temp.empty()){
        for(auto it : temp )
        {
        cout<<it<<" ";
        }   
    }
    else{
        cout<<"There were no next permutation "<<endl;
    }
}


// Optimal Solution 
void nextpermutation_optimal(vector<int> &arr){
    int n = arr.size();
    int idx = -1;
    for(int i = n - 2 ; i >= 0; i--){
        if(arr[i] < arr[i]+1){
            idx = i;
            break;
        }
    }
    if(idx == -1){
        reverse(arr.begin() , arr.end());
    }
    for(int i = n-1 ; i > idx; i--){
        if(arr[i] > arr[idx]){
            swap(arr[i] , arr[idx]);
            break;
        }
    }
    reverse(arr.begin()+idx+1 , arr.end());
    for(auto it : arr){
        cout<<it<<" ";
    }
}


// Question 8 
// Brute Force Approch 
// Take an another array for storing the array leaders 
// Take a element and move in the array if found no one is greater than it or equal to it so put it into the another array 
// Time Complexity : O(n2) and Space Complexity : O(n)
void arrayLeaders_brute(vector<int> &arr){
    vector<int> ans; // For storing the array leaders 
    for(int i = 0; i < arr.size(); i++){
        bool leader = true;
        for(int j = i + 1; j < arr.size(); j++){
            if(arr[j] > arr[i]){
                leader = false;
                break;
            }
        }
        if(leader == true){
            ans.push_back(arr[i]);
        }
    }
    // Printing the array leaders 
    for(auto it : ans){
        cout<<it<<" ";
    }
}

// Optimal Approach 
// Intitution :  Here we know the element if is greater than the rightmost part is an leader . If if we iterate from the last and take maximum of the right part if the left part is greater than the maximum element in the right part is should also be greater than all the elements in the right part and becomes a leader.
// Time Complexity : O(n) and Space Complexity : O(n)
void arrayLeaders_Optimal(vector<int> &arr){
    vector<int> ans; // For storing the leaders
    int maxi = INT_MIN;
    // For the last element to be in the part at first it checks arr[n-1] > maxi which always be greater as because maxi set as int-min which will take maxi = arr[n-1] 
    for(int i = arr.size() - 1 ; i>=0; i--){
        if(arr[i] > maxi){
            ans.push_back(arr[i]);
            maxi = max(maxi , arr[i]);
        }
    }
    // as because it starts from last 
    reverse(ans.begin() , ans.end());
    for(auto it : ans){
        cout<<it<<" ";
    }
}


// Question 9
// Brute Force Approach
// Intitution : I have an elements lets say x and I am looking for x+1 if I find I just increment my count and for finding the element we can use linear search
// Time Complexity : O(n) * O(n) another O(n) for performing linear search but it could be optimized by using binary search 
// Space Complexity : O(1)
bool ls(vector<int> &arr , int x){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == x) return true;
    }
    return false;
}
void longestsequence_Brute(vector<int> &arr){
    int x ;
    int maxi = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        int cnt = 1;
        x = arr[i];
        while(ls(arr,x+1) == true){
            x = x + 1;  // I had found i sequence and I have to update x for looking for the next one 
            // ex I pass 1 as x and we found 2 and my x is to be 2 to look for 3 
            cnt++; // Incrementin the longest sequence count
            maxi = max(cnt,maxi);
        }
    }
    cout<<"The longest sequence is : "<<maxi<<endl;
}

// Better Approach 
// Intuition : Like we are looking for x+1 in the previous approach so we know do reverse engineering like a number to be in sequence if num - 1 is present then we can say it is a sequence 
// and if that number not found we can start a sequence but taking that number as we done in else statement 
// Time Complexity : O(nlogn)+O(n) and Space Complexity : O(1)
int  longestsequence_Better(vector<int> &arr){
    sort(arr.begin() , arr.end());
    int lastSmaller = INT_MIN;   // be the previous element if it is there then we can make a sequence if it is not then start a new sequence
    int cnt = 1;
    int maxi = INT_MIN;
    if(arr.size() == 0) return 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] - 1 == lastSmaller){
            cnt++;
            lastSmaller = arr[i];
        }
        else{
            cnt = 1;
            lastSmaller = arr[i];
        }
        maxi = max(cnt , maxi); 
    }
    cout<<"The longest sequence is : "<<maxi<<endl;
}

// Optimal Approach
// Time Complexity : O(N) + O(2N)  and Space Complexity : O(n)
/*
void longestsequence_Optimal(vector<int>& arr){
    int lngest = INT_MIN;
    unordered_set<int> st;
    int cnt = 0;
    for(int i = 0 ; i < arr.size(); i++){
        st.insert(arr[i]);
    }
    // Iterate over the set 
    for(auto it : st){
        if(st.find(it - 1) == st.end()){
            cnt = 1;
            int x = it;
        }
        while(st.find(x+1) != st.end()){
            cnt+=1;
            x+=1;
        }
        lngest = max(lngest,cnt);
    }
    cout<<"The longest element sequence is : "<<lngest<<endl;
}*/


// Question 10 
// Brute Force Approach 
/*Intuition : First of all we can think of where we found zero make its row and coloumn as zero but its a wrong approach .
Lets say first we find zero at some x position so it will make its row and column as zero but the key thing is to observe when its goes to x + 1
index which was not zero previously but what it goona do it sets its row and column as zero as at x position we find zero and marked x+1 as zero .

But we can changed out thought whenever we found zero mark its row and column as zero and after which position as -1 marked is as 0.

*/

/*
// Time Complexity : O(n*m) * O(n+m) + O(n*m) near about O(n3)
// Space Complexity : O(1)

// marking row as -1
void markRow(vector<vector<int>> &arr , int i ){
    for(int j = 0 ; j < arr[0].size(); j++){
        if(arr[i][j] != 0){
            arr[i][j]=-1;
        }
    }
}
void markCol(vector<vector<int>> &arr , int j){
    for(int i = 0 ; i < arr.size(); i++){
        if(arr[i][j] != 0){
            arr[i][j] =-1;
        }
    }
}


void setMatrixzeroes_Brute(vector<vector<int>> &arr){
    int n = arr.size(); 
    int m = arr[0].size();
    for(int i = 0 ; i < n; i++){
        for(int j = 0 ; j < m; j++){
            if(arr[i][j] == 0){
                markRow(arr,i);
                markCol(arr,j);
            }
        }
    }
    // Those position marked as -1 make them as zeros 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j]==-1){
                arr[i][j]=0;
            }
        }
    }
    // print the array 
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<arr[i][j]<<",";
        }
        cout<<endl;
    }
}
*/
// Better Approach 
/*Intuition : Probably we make a two arrays one for col and one for row and mark them as per the array where we encounters zero 
and later on where we find mark either on row[i] || col[j] make that position as zero and our job will we done .*/
// Time Complexity : O(n*m) + O(n*m)  which nearly equals to O(n2)
// Space Complexity : O(n) + O(m)
void setMatrixzeroes_Better(vector<vector<int>> &arr){
    int n = arr.size();
    int m = arr[0].size();
    // Making two arrays 
    int row[n] = {0};
    int col[m] = {0};
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] == 0){
                row[i]=1;    // marking
                col[j]=1;   // marking 
            }
        }
    }
    // Now check which position is marked in col and row array from that position the element of arr which goes under this position will be marked as zero
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(row[i] || col[j]){
                arr[i][j]=0;
            }
        }
    }
    // Now print the array 
    //Ignore this while time complexity 
    for(auto it : arr){
        for(auto ele : it){
            cout<<ele<<",";
        }
        cout<<endl;
    }
}


// Optimal Approach 
/*Intuition : We are using additional arrays in better solution but here to reduce the space complexity we use mark with in the array 
, the position is becomes common point so that we use col0 variable to resolve it .*/
// Time complexity : as per better solution but space complexity : O(1)
void setMatrixzeroes_Optimal(vector<vector<int>> &arr){
    int col0 = 1;   // for avoiding the collision
    int n = arr.size(); 
    int m = arr[0].size();
    
    // Marking inside the array 
    for(int i = 0 ; i <  n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] == 0){
                arr[i][0] = 0; // row 
                if(j != 0){   // If the element present in the rowarray what we considered is zero 
                    arr[0][j] = 0;
                }
                else col0 = 0;
            }
        }
    }

    // Now iterate in the inner part without disturbing the row and col array what we considered
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){
            if(arr[i][j] != 0){
                // checking for the mark
                if(arr[i][0] == 0 || arr[0][j] == 0){
                    arr[i][j] = 0;
                }
            }
        }
    }
    // After this check for the first guy if it is zero and if the col0 variable becomes 0 
    if(arr[0][0] == 0){
        for(int i = 0 ; i < m ; i++){
            arr[0][i]=0; // make the entire column as zero 
        }
    }
    if(col0 == 0){
        for(int i = 0 ; i < n ; i++){
            arr[i][0]=0;
        }
    }

    //Later that the final output is 
    for(auto it : arr){
        for(auto ele : it){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}


// Question 11 
// Brute Force Approach 
// We see a pattern that the postions


/*

    1   2   3               7   4   1

    4   5   6       ---->   8   5   2

    7   8   9               9   6   3

(Given Matrix)    After Rotation (Matrix)

The shifted positions are - 
(1st Row)           (2nd Row)           (3rd Row)
(i)(j)    (j)(n-1-i)
[0][0] -> [0][2]    [1][0] -> [0][1]    [2][0] -> [0][0]
[0][1] -> [1][2]    [1][1] -> [1][1]    [2][1] -> [1][0]
[0][2] -> [2][2]    [1][2] -> [2][1]    [2][2] -> [2][0]

Intuition : We go to every postion and just change the element according to the position we got 
HERE n is size of array which is required to access the position and n = m .


Time Complexity : O(n2)  and Space Complexity : O(n2)

*/
void rotateImage_Brute(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> ans(m,vector<int>(n)); // for storing the rotated matrix 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            ans[j][(n-1)-i] = matrix[i][j];   
        }
    }
    // After rotation the matrix will look like 
    for(auto it : ans){
        for(auto ele : it){
            cout<<ele<<"  ";
        }
        cout<<endl;
    }
}

// Optimal Approach
/*Intuition : If we find the transpose of matrix and reverse each row 

Transpose :
    1   2   3               1   4   7                               7   4   1
    4   5   6       ----->  2   5   8       REVERSE EACH ROW ---->  8   5   2       (OUTPUT)
    7   8   9               3   6   9                               9   6   3
Now question arrises how we transpose our matrix 

So , We see the diagonal remains same and at first iteration we swap 2 and 4 , 3 and 7 and in second iteration 6 and 8 and our job is done

The shifted position are -
(i) (j)   (j)(i)
[0][1] -> [1][0] (Swap between 2 and 4)
[0][2] -> [2][0] (Swap between 3 and 7)
[1][2] -> [2][1] (Swap between 6 and 9)

Here in this problem n = m 
Time Complexity : O(n2) and Space Complexity : O(1)
*/

void rotateImage_Optimal(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    //Finding the  Transpose
    for(int i = 0; i <= n-2; i++){
        for(int j = i + 1; j <=n-1; j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }

    // Reverse the matrix
    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(),matrix[i].end());
    }

    // After transpose and reverse the output 
    for(auto it : matrix){
        for(auto ele : it){
            cout<<ele<<"  ";
        }
        cout<<endl;
    }

}



// Question 12 
/*
Understand Spiral Matrix - 
(Given Matrix) 
    
    1   2   3               (Spiral)
    4   5   6       -----> 1 2 3 6 9 8 7 4 5  It starts from left ---> bottom ----> right ----> top (Pattern)
    7   8   9
*/

void spiralMatrix(vector<vector<int>> &spiral){
    int n = spiral.size();
    int m = spiral[0].size();

    vector<int> ans;  // For storing the spiral matrix 
    int left = 0;
    int right = m-1;
    int top = 0;
    int bottom = n-1;

    // First Left to right 
    while(left <= right && top <= bottom){
        for(int i = left; i<=right; i++){
            ans.push_back(spiral[top][i]);
        }
        top++;

    // Then bottom 
        for(int i = top; i <= bottom; i++){
        ans.push_back(spiral[i][right]);
        }
        right--; // For next sequence right to left
        if(top <= bottom){
            for(int i = right; i >= left; i--){
            ans.push_back(spiral[bottom][i]);
            }
        }
        bottom--; // for next sequence bottom to top

        if(left <= right){
            for(int i = bottom; i >= top; i--){
            ans.push_back(spiral[i][left]);
            }
        }
        left++; // For starting new sequence 
}
    // Output array will look like 
    // 1 2 3 6 9 8 7 4 5 
    for(auto it : ans){
        cout<<it<<" ";
    }
    
}


// Question 13 
// Brute Force Approach 
/* Intuition 
-> Calculate all the subarray whose sub equals to the target 
*/
// Time Complexity : O(n2) and Space Complexity : O(1)
void subArray_Brute(vector<int> &arr,int k){
    int sum = 0; 
    int n = arr.size();
    int cnt=0; // For counting the numbers of pairs 
    for(int i= 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum+=arr[j];
            if(sum == k){
                cnt+=1;
            }
        }
    }
    cout<<"There are three pairs whose sum is equal to "<<k<<" is : "<<cnt<<endl;
}

// Optimal Approach 
/*Intuition : We use the concept of prefix sum we use a map data structure and just look for if previous we had find a sum == k if not then put 
it on the map data structure and continues like as follow in the code 
*/

void subArray_Optimal(vector<int> &arr, int k){
    int prefixSum = 0;
    int cnt = 0;
    int n = arr.size();
    unordered_map<int,int> mpp;
    mpp[0]=1;
    for(int i = 0; i < n; i++){
        prefixSum+=arr[i];
        int remove = prefixSum - k; 
        // If it is present 
        cnt+=mpp[remove];
        // Put it on the map
        mpp[prefixSum]++;
    }
    cout<<"There are three pairs whose sum is equal to "<<k<<" is : "<<cnt<<endl;

}
int main(){
    /*//1. Two Sum Problem 
    // The problem states return the postion of array elements which sums up and give the target value
    vector<int> arr={2,7,11,15};  
    int k=9; // target value 
    pair<int,int>p=sumProblembrute(arr);
    cout<<p.first<<" "<<p.second<<endl;    // gives 0 and 1 as arr[0]+arr[1]==9
    // For Better Approach 
    pair<int,int> p1=twoSumbetter(arr,k);
    cout<<p1.first<<" "<<p1.second;


    //2. Majority element appears > n/2 times 
    vector<int> arr={2,2,1,1,1,2,2};
    int ele=majElebrute(arr); 
    cout<<ele<<" "<<endl;   // should print as it occurred four times > n/2
    
    // For Better Approach 
    majElebetter(arr);

    // For Otimal Approach 
    majEleoptimal(arr);


    // 3. Maximum Subarray 
    // Return the   maximum  sum 
    vector<int> arr={-2,1,-3,4,-1,2,1,-5,4};
    maxSubbrute(arr);   // prints 6 as {4,-1,2,1}

    // For Optimal one 
    maxSuboptimal(arr);   // prints 6


    //4. Maximum Score with subarray minimums 
    vector<int> arr={4,3,1,5,6};
    maxScore(arr);


    //5. Stock Buy and Sell
    vector<int> arr={7,1,5,3,6,4}; 
    stock_buy_sellBrute(arr);  //Profit : 5 when you buy on day 1 and sell on day 4 and remember you cannot sell on day 0 

    // For Optimal approach 
    stock_buy_sellOptimal(arr);


    //6. Rearrange the array in alternating positive and negative items but do not change their order
    vector<int> arr={3,1,-2,-5,2,-4};     
    rearrange_Brute(arr);

    // For Optimal Approach 
    rearrange_Optimal(arr);


    //7.Next Permutation 
    vector<int> arr = {1,2,3};
    nextpermutation_brute(arr);

    // Better Approach 
    nextpermutation_better(arr);

    // Optimal Approach 
    nextpermutation_optimal(arr);


// 8. Array Leaders 
// If the element is greater than all the element on its right side or if it is equal to the maximum element on its right side it considered as leaders. The rightmost element is always be a leader 
vector<int> arr = {16,17,4,3,5,2};
// Leaders are 17 5 2 
arrayLeaders_brute(arr);

// For Optimal one
arrayLeaders_Optimal(arr);


// 9. Longest Consecutive Sequences 
// [100,4,200,1,3,2] longest sequence is 1,2,3,4  return it is size
vector<int> arr = {100,4,200,1,3,2};
longestsequence_Brute(arr);

// Better Approach 
longestsequence_Better(arr);

// Optimal Approach 
longestsequence_Optimal(arr);


// 10. Set matrix zero 
// [[1,1,1] , [1,0,1] , [1,1,1]]  output is [[1,0,1] , [0,0,0] , [1,0,1]]  where we found zero just make its row and column equal to zero
vector<vector<int>> arr = {{1,1,1} , {1,0,1} , {1,1,1}};
//setMatrixzeroes_Brute(arr);

// Better Approach 
//setMatrixzeroes_Better(arr);

// Optimal Approach 
setMatrixzeroes_Optimal(arr);


// 11.Rotate Image 
vector<vector<int>> matrix={{1,2,3},{4,5,6},{7,8,9}};
rotateImage_Brute(matrix);


// Optimal Approach 
rotateImage_Optimal(matrix);



//12.Spiral Matrix
vector<vector<int>> spiral = {{1,2,3},{4,5,6},{7,8,9}};
spiralMatrix(spiral);

*/


// 13. Subarray sum Equals to k 
vector<int> arr = {1,1,1,1,2,3};   // Return the total numbers of subarray whose sum equals to three
int k = 3;
subArray_Brute(arr,k);

// For optimal one
subArray_Optimal(arr,k);
return 0;

}