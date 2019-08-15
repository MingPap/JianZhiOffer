class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    
    //比较标号
    bool duplicate(int numbers[], int length, int* duplication) {
        if(numbers==nullptr||length<=1)
            return false;
        for(int i=0;i<length;i++)
        {
            if(numbers[i]!=i)
            {
                if(numbers[i]==numbers[numbers[i]])
                {
                    *duplication=numbers[i];
                    return true;
                }
                int tmp=numbers[i];
                numbers[i]=numbers[tmp];        //这里不能把tmp替换为numbers[i]
                numbers[tmp]=tmp;
            }
        }
        return false;
        
    }
    
    //使用哈希数组
    bool duplicate2(int numbers[], int length, int* duplication) {
        if(numbers==nullptr||length<=1)
            return false;
        int *hashm=new int[length];
        
        memset(hashm,0,length*sizeof(int));
        for(int i=0;i<length;i++)
        {
            if(!hashm[numbers[i]])
                hashm[numbers[i]]++;
            else
            {
                *duplication=numbers[i];
                return true;
            }
        }
        
        delete [] hashm;
        return false;
        
    }
};
