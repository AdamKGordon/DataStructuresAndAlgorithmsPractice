

char * longestPalindrome(char * s){
    int i, j;
    int max = 1;
    int maxIdx=0;
    int l, r;
    int curLen;
    int len = strlen(s);
    //printf("____%d %d %d\n", len, sizeof(s), sizeof(s[0]));
    char *ret;

    
    for(i=1; i<len; i++) {
        for(j=0; j<2; j++){

            if (j==0) {
                l=i-1;
                r=i+1;
                curLen=1;
            }
            else{
                l=i-1;
                r=i;
                curLen=0;
            }
            while(l>=0 && r<len) {
                if(s[l]==s[r]) {

                    curLen+=2;
                    if(curLen>max) {
                        max=curLen;
                        maxIdx = l;
                    }
                    l--;
                    r++;
                }
                else{
                    curLen=1;
                    l=i-1;
                    r=i+1;
                    break;
                }
            }
        }   
    }

    ret = (char*) malloc(sizeof(char)*(max+1));
    for(i=0; i<max; i++){
        ret[i] = s[maxIdx+i];    

    }
    ret[max] = '\0';

    return ret;
}