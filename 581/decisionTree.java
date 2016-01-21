
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
 
class node {

    String name;
    char cost;
    node left;
    node right;
    node parent;
    // to store actions
    node[] leaf;

    public node(String name, char cost) {
        this.name = name;
        this.cost = cost;
        left = null;
        right = null;
        parent = null;
        leaf = new node[20];
    }
}

// class to create tree , query
public class decisionTree {

    // queue to make tree using level order tree traversal

    Queue<node> queue = new LinkedList<node>();
    //root of node
    node root;
    // to store the name of conditions 
    String[] conditions = new String[50];

    // to store yes or no of conditions
    char mat[][] = new char[100][100];

    String store;
    boolean fg = false;
    String defaultString;
    // to store no. of conditions
    int last_index;

    // function to add condition to tree
    void insert_node(String nam) {
        // if queue has no element just add start node and  return
        if (queue.size() == 0) {
            root = new node(nam, '$');
            queue.add(root);
            return;
        }
        node temp;
        int k = queue.size();
        // add new node to all nodes which are present in queue
        while (k != 0) {
            temp = queue.remove();
            k--;
            node left_child = new node(nam, 'Y');
            node right_child = new node(nam, 'N');
            left_child.parent = temp;
            right_child.parent = temp;
            temp.left = left_child;
            temp.right = right_child;
            queue.add(left_child);
            queue.add(right_child);
        }

    }

    //function to add actions
    void add_leaf(char arr[], String nam) {
        int k = 0;
        node temp = root;
        //iterate until we did not find leaf  node
        while (temp.left != null && temp.right != null) {
            if (temp.left.cost == arr[k++]) {
                temp = temp.left;
            } else {
                temp = temp.right;
            }

        }
        int l = 0;
        // find the index where we have to add new action
        while (temp.leaf[l] != null) {
            l++;
        }

        // add action
        node tmp = new node(nam, arr[k - 1]);
        temp.leaf[l] = tmp;
        tmp.parent = temp;

    }

    // function to query 
    void query() {
        // to take input from user
        Scanner inp = new Scanner(System.in);
        String tmp;
        int i = 0;
        node temp = root;
        while (conditions[i] != null) {
            System.out.println(conditions[i] + "? Y or N");
            tmp = inp.next().toUpperCase();
            if (tmp.equals("Y")) {
                if (temp.left.cost == 'Y') {
                    temp = temp.left;
                } else {
                    temp = temp.right;
                }
            } else {
                if (temp.left.cost == 'N') {
                    temp = temp.left;
                } else {
                    temp = temp.right;
                }
            }
            i++;
        }
        i = 0;
        // print corresponding action
        while (temp.leaf[i] != null) {
            System.out.println(temp.leaf[i].name);
            i++;
        }

    }

    //print tree using level order traversal
    void print_tree() {
        Queue<node> q = new LinkedList<node>();
        q.add(root);
        q.add(null);
        int fg = 0;
        while (q.size() != 0) {
            node tmp = q.remove();
            if (tmp == null) {
                System.out.println();
                if (fg != 1) {
                    q.add(null);
                }
                continue;
            }
            System.out.print("[" + tmp.cost + " " + tmp.name + "--->[");
            if (tmp.left == null && tmp.right == null) {
                int k = 0;
                fg = 1;
                while (tmp.leaf[k] != null) {
                    System.out.print("(" + tmp.leaf[k].name + ", " + tmp.leaf[k].cost + "),");
                    k++;
                }
                System.out.println("]");
            } else {
                System.out.print("(" + tmp.left.name + ", " + tmp.left.cost + "),");
                System.out.print("(" + tmp.right.name + ", " + tmp.right.cost + ")]");
                q.add(tmp.left);
                q.add(tmp.right);
            }

        }
    }

    //function to create decision tree
    public void createTree() throws FileNotFoundException, IOException {
        // input file reader
        Scanner input = new Scanner(new File("inp.txt"));
        input.nextLine();
        int i, j;
        i = 0;
        store = "";
        this.insert_node("Start_node");
        while (input.hasNextLine()) {
            String temp = input.nextLine();
            store = store + temp + "\n";
            if (temp.equals("Actions")) {
                break;
            }
            j = 0;
            String tp = "";
            for (String tmp : temp.split(" ")) {
                if (tmp.equals("Y")) {
                    mat[i][j++] = 'Y';
                } else if (tmp.equals("N")) {
                    mat[i][j++] = 'N';
                } else {
                    tp = tp + " " + tmp;
                }
            }
            this.insert_node(tp);
            this.conditions[i] = new String(tp);
            i++;
        }
        last_index = i;
        while (input.hasNextLine()) {
            String temp = input.nextLine();
            String tp = "";
            char arr[] = new char[100];
            j = 0;
            store = store + temp + "\n";
            for (String tmp : temp.split(" ")) {
                if (tmp.equals("Y")) {
                    arr[j++] = 'Y';
                } else if (tmp.equals("N")) {
                    arr[j++] = 'N';
                } else {
                    tp = tp + " " + tmp;
                }
            }
            char arr2[] = new char[i + 2];
            for (int l = 0; l < j; l++) {
                int g = 0;
                if (arr[l] == 'Y') {
                    for (int p = 0; p < i; p++) {
                        arr2[g++] = mat[p][l];
                    }
                    this.add_leaf(arr2, tp);
                }
            }
        }
        input.close();
    }

    public static void main(String[] args) throws FileNotFoundException, IOException {
        decisionTree dt = new decisionTree();

        dt.createTree();

        int t = 10;
        //dt.print_tree();
        
        dt.print_tree();
        
        // To add new conditions and actions
        //dt.addNewCondition();
        //dt.addNewAction();
        
        //Query Check
        while (t-- != 0)
         dt.query();
        //dt.addNewAction();
        //while (t-- != 0)
        //dt.query();
        
        //To print tree after adding new condition and action iff query part is comment.
        //dt.print_tree();
    }

    // function to add new condition at run time
    private void addNewCondition() throws IOException {
        if (!fg) {
            defaultString = "Conditions\n";
            defaultString += store;
            fg = true;
        }
        Scanner inpt = new Scanner(System.in);
        System.out.println("Enter number of conditions : ");
        int t = inpt.nextInt();
        inpt.nextLine();
        System.out.println("Enter your conditions : ");
        while (t != 0) {
            String temp = inpt.nextLine();
            this.store = temp + "\n" + this.store;
            t--;
            //System.out.println("Store " + store);
        }

        FileWriter fw = new FileWriter(new File("inp.txt"));
        store = "Conditions\n" + store;
        fw.write(store);
        fw.close();
        store = null;
        queue.clear();
        this.createTree();
        fw = new FileWriter(new File("inp.txt"));

        fw.write(defaultString);
        fw.close();
    }

    // function to add new action at run time
    private void addNewAction() {
        Scanner ipt = new Scanner(System.in);
        System.out.println("Enter number of actions : ");
        int t = ipt.nextInt();
        ipt.nextLine();
        System.out.println("Enter actions : ");
        char arr[] = new char[100];
        while (t-- != 0) {
            String temp = ipt.nextLine();
            store += temp + "\n";
            String tp = "";
            int j = 0;
            for (String tmp : temp.split(" ")) {
                if (tmp.equals("Y")) {
                    arr[j++] = 'Y';
                } else if (tmp.equals("N")) {
                    arr[j++] = 'N';
                } else {
                    tp = tp + " " + tmp;
                }
            }

            char arr2[] = new char[last_index + 1];
            for (int l = 0; l < j; l++) {
                int g = 0;
                if (arr[l] == 'Y') {
                    for (int p = 0; p < last_index; p++) {
                        arr2[g++] = mat[p][l];

                    }

                    this.add_leaf(arr2, tp);
                }

            }
        }
    }

}

/*
 C5 N N N N N N N N
 C4 Y Y Y N N N N N

 A6 N N N Y Y Y Y N
 A7 Y Y Y N N Y Y N
 */