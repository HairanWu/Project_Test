/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    typedef struct{  
        int id;  
        int value;  
        UT_hash_handle hh; 
    } Hash_user_t;  
    
     Hash_user_t *users=NULL,*tmp=NULL;  
     
     int *ReturnArry= malloc(2*sizeof(int));
     
     int x=0;
     
     for (int i = 0; i < numsSize; i++) {
        
         x = target-nums[i];
        
         HASH_FIND_INT(users, &x, tmp);
         
         //if found
         if(tmp != NULL){
             ReturnArry[0]= tmp->id + 1;
             ReturnArry[1]= i + 1;
             
             return ReturnArry;
         }
         
          tmp = (Hash_user_t*)malloc(sizeof(Hash_user_t));
          
          tmp->id = i;
          
          tmp->value =  nums[i];
         
          HASH_ADD_INT(users,value,tmp);  
    }
}
