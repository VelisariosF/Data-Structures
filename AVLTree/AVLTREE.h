#include <cstddef>
#include <string>
#include<cstdio>
#include<sstream>
using namespace std;
//#include<algorithm>
#define pow2(n) (1 << (n))
//#if !defined(nullptr)
#define nullptr NULL
struct avl_node//Δομή κόμβου δέντρου
{
    string data;//Δεδομένα κόμβου
    int appearances = 0;
    struct avl_node *left;//αριστερό του παιδί
    struct avl_node *right;//δεξιό του παιδί
};
class AVLTREE
{
    avl_node *root;//Δημιουργία Δέντρου-1ου κόμβου
    public:
        AVLTREE()//αρχικοποίηση δέντρου
        {
            root = NULL;//με κενό
        }
        int height(avl_node *);
        int diff(avl_node *);
        avl_node *minValueNode(avl_node *);
        avl_node *rr_rotation(avl_node *);
        avl_node *ll_rotation(avl_node *);
        avl_node *lr_rotation(avl_node *);
        avl_node *rl_rotation(avl_node *);
        avl_node* balance(avl_node *);
        avl_node* insert(avl_node *, string );
        void insertion(string itemm){root=insert(root, itemm);}
        avl_node* deletee(avl_node *, string );
        void deleletion(string item){root=deletee(root, item);}
        bool searchkey(avl_node *,string k);
        bool insertkey(string ke)//Αναζήτηση στοιχείου στο δέντρο
        {
            return searchkey(root,ke);
        }
        int sizeoftree(avl_node *);
        int get_the_size()
        {
            return sizeoftree(root);
        }
        string get_the_m(avl_node *);
        string get_the_min()
        {
            return get_the_m(root);
        }

        void inorder(avl_node* root);
};



//Συνάρτηση Εύρεσης Mεγαλύτερου ύψους AVL Δέντρου
int AVLTREE::height(avl_node *temp)//temp ο εκάστοτε κόμβος
{
    int h = 0;//Αρχικοποιεί το ύψος ίσο με το 0
    if (temp != NULL)//τερματίζει την αναδρομική διαδικασία αν ο κόμβος δεν δείχνει ουτε αριστερά ούτε δεξιά άρα είναι null
    {
        int l_height = height (temp->left);//Θέτει το αριστερό ύψος καλώντας αναδρομικά τη συνάρτηση αριστερότερα
        int r_height = height (temp->right);//θέτει το δεξί ύψος καλώντας αναδρομικά τη συνάρτηση δεξιότερα
        int max_height = std::max (l_height, r_height);//Βρίσκει το μεγαλύτερο απ τα δύο ύψη, Αριστερό ή Δεξί
        h = max_height + 1;//θέτει ως ύψος το μεγαλύτερο + 1
    }
    return h;//επιστρέφει το μεγαλύτερο φύλο σε ύψος
}
//Συνάρτηση Διαφοράς Ύψους
int AVLTREE::diff(avl_node *temp)//temp ο εκάστοτε κόμβος
{
    int l_height = height (temp->left);//Θέτει το αριστερό ύψος καλώντας την αναδρομική συνάρτηση height
    int r_height = height (temp->right);//θέτει το δεξί ύψος καλώντας την αναδρομική συνάρτηση height
    int b_factor= l_height - r_height;//Θέτει ως συντελεστή εξισορρόπησησς την διαφορά αριστερού με δεξιού μεγαλύτερου φύλου
    return b_factor;//τον επιστρέφει
}

// Δεξιά Περιστροφή
avl_node *AVLTREE::rr_rotation(avl_node *parent)//*parent ο κόμβος που δεχόμαστε
{
    avl_node *temp;//temp ο εκάστοτε κόμβος-Αρχικά ο 1ος και μεγαλύτερος
    temp = parent->right;//Θέσε στον 1ο κόμβο την τιμή του δεξιού παιδιού του πατέρα κόμβου
    parent->right = temp->left;//θέσε στο δεξί παιδί του πατέρα την τιμή του αριστερού παιδιού του temp
    temp->left = parent;//Θέσε στην τιμή του αριστερού παιδιού του temp την τιμή του πατέρα κόμβου
    return temp;//Επέστρεψε το δέντρο temp
}

// Αριστερή Περιστροφή

avl_node *AVLTREE::ll_rotation(avl_node *parent)//Δέχεται τον πατέρα κόμβο
{
    avl_node *temp;//temp ο εκάστοτε κόμβος-Αρχικά ο 1ος και μεγαλύτερος
    temp = parent->left;//Θέσε στον 1ο κόμβο την τιμή του αριστερού παιδιού του πατέρα κόμβου
    parent->left = temp->right;//θέσε στο αριστερό παιδί του πατέρα την τιμή του δεξιού παιδιού του temp
    temp->right = parent;//Θέσε στην τιμή του δεξιού παιδιού του temp την τιμή του πατέρα κόμβου
    return temp;//Επέστρεψε το δέντρο temp
}


// Αριστερή-Δεξιά Περιστροφή

avl_node *AVLTREE::lr_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}


// Δεξιά-Αριστερή Περιστροφή
avl_node *AVLTREE::rl_rotation(avl_node *parent)
{
    avl_node *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}


// Εξισορρόπιση AVL Δέντρου

avl_node *AVLTREE::balance(avl_node *temp)//*temp ο εκάστοτε κόμβος-temp το δέντρο
{
    int bal_factor = diff (temp);//καλεί τη συνάρτηση διαφοράς ύψους
    if (bal_factor > 1)//Αν η διαφορά ύψους είναι μεγαλύτερη από 1 υπάρχει πρόβλημα- προεξέχει απ την αριστερή πλευρά
    {
        if (diff (temp->left) > 0)//Αν η διαφορά ύψους στο αριστερά υποδέντρο είναι μεγαλύτερη του 0
            temp = ll_rotation (temp);//Προεξέχει από αριστερά άρα κάνε αριστερή αριστερή περιστροφή
        else//αλλιώς
            temp = lr_rotation (temp);//Προεξέχει από δεξιά ή μπορεί και όχι άρα κάνε αριστερή δεξιά περιστροφή
    }
    else if (bal_factor < -1)//Αλλιώς αν η διαφορά ύψους είναι μικρότερη από -1 υπάρχει πρόβλημα- προεξέχει απ την δεξιά πλευρά
    {
        if (diff (temp->right) > 0)//Αν η διαφορά ύψους στο δεξί υποδέντρο είναι μεγαλύτερη του 0
            temp = rl_rotation (temp);//Προεξέχει το αριστερό κλαδί άρα κάνε δεξια αριστερή περιστροφή
        else//αλλιώς
            temp = rr_rotation (temp);//Προεξέχει το αριστερό κλαδί ή μπορεί και όχι αρα κάνε δεξιά δεξιά περιστροφή
    }
    return temp;//Επέστρεψε το δέντρο
}
// Διαγραφή στοιχείου στο AVL δέντρο
avl_node *AVLTREE::deletee(avl_node *root, string value)
{
    if (root == NULL)
    {
        return root;
    }
    if (value < root->data)//Αλλιώς αν η τιμή value είναι μικρότερη από την τιμή του εκάστοτε κόμβου
    {
        root->left = deletee(root->left, value);//Κάλεσε ξάνα αναδρομικά την συνάρτηση deletee αριστερότερα
        root = balance (root);//Εξισορρόπησε το δέντρο
    }
    else if (value > root->data)//Αλλιώς αν η τιμή value είναι μεγαλύτερη ή ίση απο την τιμή του εκάστοτε κόμβου
    {
        root->right = deletee(root->right, value);//Κάλεσε ξάνα αναδρομικά την συνάρτηση deletee δεξιότερα
        root = balance (root);//Εξισορρόπησε το δέντρο
    }
    else         // node with only one child or no child
    {
        if ((root->left == NULL) || (root->right == NULL))
           {
               avl_node *temp= root->left?root->left:root->right;
               if(temp==NULL)
                {
                    temp=root;
                    root=NULL;
                }
                else
                    *root= *temp;
                delete temp;
           }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            avl_node *temp = minValueNode(root->right);
            // Copy the inorder successor's
            // data to this node
            root->data = temp->data;
            // Delete the inorder successor
            root->right = deletee(root->right,  temp->data);
        }
    }
    return root;
}
// Εισαγωγή στοιχείου στο AVL δέντρο
avl_node *AVLTREE::insert(avl_node *root, string value)//*root ο εκάστοτε κόμβος του δέντρου root- Αρχικά ο 1ος ,value η τιμή
{
    if(searchkey(root, value)){
      root->appearances++;
      return root;
    }
    if (root == NULL)//Aν είναι κενός ο κόμβος και δεν έχει τιμή
    {
        root = new avl_node;//Πρόσθεσε νέο κόμβο στο δέντρο
        root->data = value;//Δώστου την τιμή value
        root->appearances ++;
        root->left = NULL;//Αρχικοποίησε το αριστερό παιδι με κενό
        root->right = NULL;//Αρχικοποίησε το δεξί παιδί με κενό
        return root;//Επέστρεψε το Δέντρο
    }
    else if (value < root->data)//Αλλιώς αν η τιμή value είναι μικρότερη από την τιμή του εκάστοτε κόμβου
    {
        root->left = insert(root->left, value);//Κάλεσε ξάνα αναδρομικά την συνάρτηση insert αριστερότερα
        root = balance (root);//Εξισορρόπησε το δέντρο
    }
    else if (value >= root->data)//Αλλιώς αν η τιμή value είναι μεγαλύτερη ή ίση απο την τιμή του εκάστοτε κόμβου
    {
        root->right = insert(root->right, value);//Κάλεσε ξάνα αναδρομικά την συνάρτηση insert δεξιότερα
        root = balance (root);//Εξισορρόπησε το δέντρο
    }
    return root;//Επέστρεψε το δέντρο-Τερμάτισε την Αναδρομική Συνάρτηση
}

bool AVLTREE::searchkey(avl_node *root,string k)//Αναζήτηση στοιχείου στο δέντρο
{
    if (root!=NULL)
    {
        if(k==root->data)
            return true;
        else if (k<root->data)
            searchkey(root->left,k);
        else if(k > root->data)
            searchkey(root->right,k);
    }
    else
        return false;
}
int AVLTREE::sizeoftree(avl_node *tree) //επιστροφή μεγέθους δέντρου
{
    if(tree!=NULL)
    {
        return 1+sizeoftree(tree->left)+sizeoftree(tree->right);
    }
    else
        return 0;
}
avl_node *AVLTREE::minValueNode(avl_node *root)
{
    while (root->left != NULL)
    {
         root = root->left;
    }
    return root;
}
string AVLTREE::get_the_m(avl_node *root)//επιστροφή μικρότερης τιμής δέντρου
{
    while(root->left !=NULL)
    {
        root=root->left;
    }
    return root->data;
}

void AVLTREE:: inorder(avl_node* root){
    if(!root)
    {
        return;
    }
    
    inorder(root->left);
    cout << "Word:" << this->root->data << " Appearances:" << this -> root->appearances << endl;
    inorder(root->right);
}
