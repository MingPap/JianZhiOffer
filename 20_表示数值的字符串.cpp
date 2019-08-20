class Solution {
public:
    bool isNumeric(char* string)
    {
        if(string == nullptr||*string=='\0')
            return false;
        if(*string=='+'||*string=='-')
        {
            ++string;
            if(*string=='\0')
                return false;
        }
        int dot=0,nume=0,num=0;
        while(*string!='\0')
        {
            if(*string>='0'&&*string<='9')
            {
                ++string;
                num++;
            }
            else if(*string=='.')
            {
                if(dot>0||nume>0)
                    return false;
                dot++;
                string++;
            }
            else if(*string=='e'||*string=='E')
            {
                if(nume>0||num==0)
                    return false;
                nume++;
                string++;
                if(*string=='+'||*string=='-')
                    string++;
                if(*string=='\0')
                    return false;
            }
            else
                return false;
        }
        
        return true;
    }

};
