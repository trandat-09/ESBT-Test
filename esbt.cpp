//Mức độ dễ
//reverse string --- thời gian nghiên cứu và làm: 30ph
class Solution {
public:
    int reverse(int x) {
        if(!x){
            return 0;
        }
        long long result = 0;
        while(x) {
            result = result * 10 + x % 10;
            x /= 10;
            if ( result > INT_MAX || result < INT_MIN )
                return 0;
        }
    
    return (int)result;
    }
};

//Employees Earning More Than Their Managers ---- thời gian nghiên cứu và làm 30ph (sử dụng SELF-JOIN SQL)
SELECT e1.Name AS Employee
FROM Employee e1, Employee e2
WHERE e1.ManagerId = e2.Id AND e1.Salary > e2.Salary


//merge-two-sorted-lists -- 50ph
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        ListNode* result = NULL;  
      
        if (l1 == NULL){
            return(l2);  
        }
        else if (l2 == NULL){            
            return(l1);  
        }  

        if (l1->val <= l2->val)  
        {  
            result = l1;  
            result->next = mergeTwoLists(l1->next, l2);  
        }  
        else
        {  
            result = l2;  
            result->next = mergeTwoLists(l1, l2->next);  
        }  
        return(result);  
        }
};

//Longest Palindromic Substring -- 60ph
class Solution {
public:
    string longestPalindrome(string s) {
        
         int n = s.size();
        
        int maxLength = 1, start = 0; 

        for (int i = 0; i < n; i++) { 
            for (int j = i; j < n; j++) { 
                int flag = 1; 
 
                for (int k = 0; k < (j - i + 1) / 2; k++)
                    if (s[i + k] != s[j - k]) 
                        flag = 0; 

                if (flag && (j - i + 1) > maxLength) { 
                    start = i; 
                    maxLength = j - i + 1; 
                } 
            } 
        } 
        return s.substr(start, maxLength);
    }
};