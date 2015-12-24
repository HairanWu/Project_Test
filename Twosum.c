/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    typedef struct example_user_t {  
        int id;  
        int value;  
        UT_hash_handle hh; 
    } example_user_t;  
    
     example_user_t *users=NULL,*tmp=NULL;  
     
     int *returnarry= malloc(2*sizeof(int));
     
     int x=0;
     
    for (int i = 0; i < numsSize; i++) {
        
         x = target-nums[i];
        
         HASH_FIND_INT(users, &x, tmp);
         
         if(tmp != NULL){
             returnarry[0]= tmp->id + 1;
             returnarry[1]= i + 1;
             return returnarry;
         }
         
          tmp = (struct example_user_t*)malloc(sizeof(struct example_user_t));
          
          tmp->id = i;
          
          tmp->value =  nums[i];
         
          HASH_ADD_INT(users,value,tmp);  
    }
}
