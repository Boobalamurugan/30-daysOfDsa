#include<stdio.h>
#include<string.h>

int main(){
    char str[]="2k21aids@kiot.ac.in";
    char output_str[]="";
    char special_char[]="";
    char number[]="";
    for(int i=0;i<strlen(str);i++){
        if(str[i]>='a'&&str[i]<='z'){
            strncat(output_str,str[i]);
        }
        else if(str[i]>='0'&&str[i]<='9'){
            strncat(special_char,str[i]);
        }
        else{
           strncat(number,str[i]);
        }
    }

    printf("%s\n",output_str);
    printf("%s\n",special_char);
    printf("%s",number);


}