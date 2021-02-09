int lengthOfLongestSubstring(char* s) {
    int retVal = 0;
    int subLen = 0;
    int longestSubLen = 0;
    int lStart=0;
    int l=lStart, r;
    
    if(!s[0]) {
       return 0;
    }
    if(!s[1]) {
       return 1;
    }
        
    for(r=1; s[r] /*nullTerm*/; r++) {
        for(l=lStart; l<r; l++) {
            if(s[l] == s[r]) {
                lStart = l+1;
                break;
            }
        }
        subLen = r-lStart;
        if(subLen > longestSubLen) {
            longestSubLen = subLen;
        }
    }
    
    
    return longestSubLen+1;
}