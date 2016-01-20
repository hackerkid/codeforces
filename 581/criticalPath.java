package lab_xam2;

import java.io.*;
import static java.lang.Integer.*;
import static java.lang.Math.min;
import java.util.*;

public class criticalPath {

    static String task[] = new String[100];
    static int time[] = new int[100];
    static String dep[][] = new String[100][100];
    static int dep_n[] = new int[100];
    static int start[] = new int[100];
    static int end[] = new int[100];
    static int s2[] = new int[100];
    static int e2[] = new int[100];
    static int slack_start[] = new int[100];
    static int slack_end[] = new int[100];
    static Map<Character, Integer> charindex = new HashMap<Character, Integer>();
    static String task_new[] = new String[100];
    static int time_new[] = new int[100];
    static String dep_new[][] = new String[100][100];
    static int dep_n_new[] = new int[100];
    static int start_new[] = new int[100];
    static int end_new[] = new int[100];
    public static void main(String[] args) throws FileNotFoundException, IOException {
        FileInputStream in = new FileInputStream("input.txt");

        String a = "", t = "";
        int flag = 0, l = 0, i = 0, j = 0;

        Scanner sc = new Scanner(in);

        while (sc.hasNextLine()) {
            a = sc.nextLine();
            a = a + "  ";
            if (flag == 0) {
                flag = 1;
                continue;
            }

            t = "";
            i = 0;
            //System.out.print(a.charAt(i));
            while (a.charAt(i) != ' ') {
                t = t + a.charAt(i);
                i++;
                //System.out.print(a.charAt(i));
            }
            task[l] = t;
            charindex.put(a.charAt(0), l);
            i++;
            //System.out.print(a.charAt(i));

            t = "";
            while (a.charAt(i) != ' ') {
                t = t + a.charAt(i);
                i++;
            }
            time[l] = Integer.parseInt(t);
            i++;

            j = 0;
            while (a.charAt(i) != ' ') {
                t = "";
                while (a.charAt(i) != ',' && a.charAt(i) != ' ') {
                    t = t + a.charAt(i);
                    i++;
                }
                i++;
                dep[l][j++] = t;
            }
            if (dep[l][0].equals("-")) {
                dep_n[l] = 0;
            } else {
                dep_n[l] = j;
            }
            l++;
        }
        
        /* START TIME AND END TIME WITH TOPOLOGICAL SORTING */
        int temp_start;
        int[] visited = new int[100];
        for(i=0; i<l; i++) {
            visited[i]=0;
        }
        int fg;
        int f=0;
        int[] n = new int[100];
        int k=0;
        for(int x=0; x<l; ) {
            int[] v = new int[100];
            int h=0;
            for(i=0; i<l; i++) {
                if(visited[i]==0) { 
                if(f==0 && dep_n[i]==0) {
                    start[i]=0;
                    end[i]=time[i];
                    v[h++]=i;
                    //visited[i]=1;
                    x++;
                    //System.out.println(task[i]+" "+start[i]+" "+end[i]);
                    continue;
                }
                else {
                    fg=0;
                    //System.out.println(x+" "+i);
                    for(j=0; j<dep_n[i]; j++) {
                        //System.out.println(task[i]+" "+dep[i][j].charAt(0));
                       if(visited[charindex.get(dep[i][j].charAt(0))] == 0) {
                           fg=1;
                           break;
                       } 
                    }
                    if(fg==0) {
                        temp_start=0;
                        v[h++]=i;
                        //visited[i]=1;
                        for(j=0; j<dep_n[i]; j++) {
                            temp_start = max(temp_start, end[charindex.get(dep[i][j].charAt(0))]);
                        }
                        start[i]=temp_start;
                        end[i]=start[i]+time[i];
                        //System.out.println(task[i]+" "+start[i]+" "+end[i]);
                        x++;
                    }
                }
                }
            }
            for(i=0; i<h; i++) {
                n[k]=v[i];
                //System.out.println(k+" "+n[k]+" "+task[n[k]]);
                visited[v[i]]=1;
                k++;
            }
            f=1;
        }
        
        for(i=0; i<l; i++) {
            int p=n[i];
            task_new[i] = task[p];
            time_new[i] = time[p];
            j=0;
            do {
                dep_new[i][j] = dep[p][j];
                j++;
            }while(j<dep_n[p]);
            dep_n_new[i] = dep_n[p]; 
            start_new[i] = start[p];
            end_new[i] = end[p];
        }
        /*
        //Start Time
        for (i = 0; i < l; i++) {
            temp_start = 0;
            for (j = 0; j < dep_n[i]; j++) {
                for (int k = 0; k < l; k++) {
                    if (task[k].equals(dep[i][j])) {
                        temp_start = max(temp_start, start[k] + time[k]);
                    }
                }
            }
            start[i] = temp_start;
        }

        //End Time
        for (i = 0; i < l; i++) {
            end[i] = start[i] + time[i];
        }
        */
        System.out.println("NORMAL START & END TIME");
        for (i = 0; i < l; i++) {
            System.out.println(task_new[i] + "  " + time_new[i] + "  " + start_new[i] + "  " + end_new[i]);
        }
        
        //Critical Path
        int max_time = 0, index = 0;
        for (i = 0; i < l; i++) {
            if (end_new[i] > max_time) {
                max_time = end_new[i];
                //index=i;
            }
        }
        for(i=0; i<l; i++) {
            slack_start[i]=start_new[i];
            slack_end[i]=end_new[i];
        }
        j=1;
        
        for (i = 0; i < l; i++) {
            if (max_time == end_new[i]) {
                String s="";
                System.out.print("Critical Path "+ j + ": ");
                s=print_critical_path(i, l, s);
                System.out.println();
                System.out.println("SLACK TIME "+ j + ": ");
                print_slack_time(i, l, s);
                System.out.println();
                j++;
            }
        }
        System.out.println();
    }

    static String print_critical_path(int i, int l, String s) {
        if (dep_n_new[i] == 0) {
            s2[i] = start_new[i];
            e2[i] = end_new[i];
            System.out.print(task_new[i] + ' ');
            s+=task_new[i];
            return s;
        }
        int max_time = 0, index = 0;
        for (int j = 0; j < dep_n_new[i]; j++) {
            for (int k = 0; k < l; k++) {
                if (task_new[k].equals(dep_new[i][j])) {
                    if (end_new[k] > max_time) {
                        index = k;
                        max_time = end_new[k];
                    }
                }
            }
        }
        
        s=print_critical_path(index, l, s);
        s+=task_new[i];
        System.out.print(task_new[i] + ' ');
        s2[i] = start_new[i];
        e2[i] = end_new[i];
        return s;
    }

    private static void print_slack_time(int index, int l, String s) {
        //System.out.println(s);
        int len=s.length();
        int f,fg,i,j,k,temp;
        for(i = l-1; i>=0; i--) {
            /* Present In Critical Path Or Not */
            f=0;
            for(j=0; j<len; j++) {
                if(task_new[i].charAt(0) == s.charAt(j)) {
                    f=1;
                    break;
                }
            }
            /* If Not Compute Slack Time */ 
            if(f==0) {
                fg=0;
                temp=Integer.MAX_VALUE;
                for(j=0; j<l; j++) {
                    for(k=0; k<dep_n_new[j]; k++) {
                        if(task_new[i].charAt(0) == dep_new[j][k].charAt(0)) {
                            fg=1;
                            //System.out.println(task[i]+" "+i+" "+slack_start[j]);
                            temp = min(temp, slack_start[j]);
                        }
                    }
                }
                if(fg == 1) {
                    int t = temp - slack_end[i];
                    //System.out.println("t : " + t + " temp : " + temp);
                    slack_start[i] += t;
                    slack_end[i] += t;
                }
                else {
                    int t=slack_end[charindex.get(s.charAt(len-1))]-slack_end[i];
                    slack_start[i] += t;
                    slack_end[i] += t;
                }
            }
        } 
        
        for (i = 0; i < l; i++) {
            System.out.println(task_new[i] + "  " + time_new[i] + "  " + slack_start[i] + "  " + slack_end[i]);
        }
    }
}