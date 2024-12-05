#include <stdio.h>
#include<string.h>
#include<ctype.h>
int main(){
	char s1[201],s2[201];
	int count[26]={0};
	scanf("%s",s1);
	scanf("%s",s2);
	int len1=strlen(s1);
	int len2=strlen(s2);
	if(len1>len2){
		printf("false");
	}
	else{
		// for(int i=0;i<len1;i++){
		// 	s1[i]=tolower(s1[i]);
		// }
		// for(int i=0;i<len2;i++){
		// 	s2[i]=tolower(s2[i]);
		// }
		for(int i=0;i<len1;i++){
			count[s1[i]-'a']++;
		}
		int t=0;
		while(1){
			int windowcount[26]={0};
			
            for(int j=0;j<len1;j++){
				windowcount[s2[t+j]-'a']++;
			}

			int cou=0;
			
            for(int i=0;i<26;i++){
                if(count[i]==windowcount[i]){
                    cou++;
                }
			}
			if(cou==26)
                break;

			t++;

			if(t>len2-len1) {
                printf("false");
                break;
			}
		}
		for(int i=0;i<len1;i++){
            printf("%c",s2[t+i]);
		}
	}
	return 0;

}
