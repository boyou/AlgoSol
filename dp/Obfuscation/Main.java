import java.util.*;
import java.io.*;

public class Main {
    private static final int M=26;
    public static void main(String args[])throws IOException{
        BufferedReader stdin=new BufferedReader(
                new InputStreamReader(System.in));
        int tc=Integer.parseInt(stdin.readLine());
        while((tc--)!=0){
            String str=stdin.readLine();
            String temp;
            /* build the dictionary */
            int n=Integer.parseInt(stdin.readLine());
            int m=str.length();
            int cnt=0;
            int maxL=0;
            int[][] sub=new int [m][m];
            int[] pos=new int [n+1];
            int[] num=new int [n+1];
            List<String> dic=new ArrayList<String>(n);
            Map<String,Integer> mapping=new HashMap<String,Integer>();
            for(int i=0;i<n;i++){
                dic.add(i,temp=stdin.readLine());
                if(temp.length()>maxL)
                    maxL=temp.length();
                /* the transformation */
                char[] seq=new char [M+2];
                seq[0]=temp.charAt(0); // first letter
                seq[1]=temp.charAt(temp.length()-1); // last letter
                // count number of occurances
                for(int j=0;j<M;j++)
                    seq[j+2]=1;
                for(int j=0;j<temp.length();j++){
                    ++seq[temp.charAt(j)-'a'+2];
                }
                temp=new String(seq);
                if(mapping.get(temp)==null){
                    mapping.put(temp,++cnt);
                }
                int k=mapping.get(temp);
                pos[k]=i; // we can record any one here
                ++num[k];
            }
            /* process the target string */
            for(int i=0;i<m;i++){
                char[] seq=new char [M+2];
                seq[0]=str.charAt(i);
                for(int j=0;j<M;j++)
                    seq[j+2]=1;
                for(int j=i;j<m&&j<i+maxL;j++){
                    /* O(1) time update */
                    seq[1]=str.charAt(j); // update last letter
                    ++seq[str.charAt(j)-'a'+2]; // update the count
                    Integer t=mapping.get(new String(seq));
                    if(t!=null)
                        sub[i][j]=t; // sub[i][j] is equal to f(S(i,j)) in the document
                }
            }
            /* solve */
            int[] dp=new int [m];
            int[] s=new int [m];
            for(int i=m-1;i>=0;i--){
                dp[i]=num[sub[i][m-1]];
                if(dp[i]>1)
                    continue; // when greater than 1, no need to continue(already ambiguous)
                if(num[sub[i][m-1]]>=1)
                    s[i]=-1; // a single word to the end
                /* the calculation */
                for(int j=i;j<m-1&&j<i+maxL;j++){
                    int k=num[sub[i][j]]*dp[j+1];
                    dp[i]+=k;
                    if(dp[i]>1)
                        break;
                    if(k>=1)
                        s[i]=j; // a word to position j
                }
            }
            /* output */
            if(dp[0]==0){
                System.out.println("impossible");
            }
            else if(dp[0]==1){
                StringBuilder ans=new StringBuilder();
                int ps=0;
                while(true){
                    if(s[ps]==-1){
                        ans.append(dic.get(pos[sub[ps][m-1]]));
                        break;
                    }
                    else{
                        ans.append(dic.get(pos[sub[ps][s[ps]]]));
                        ans.append(' ');
                        ps=s[ps]+1;
                    }
                }
                System.out.println(ans);
            }
            else{
                System.out.println("ambiguous");
            }
        }
        stdin.close();
    }
}
