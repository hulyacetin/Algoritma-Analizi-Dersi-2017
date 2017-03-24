#include <iostream>
#include <cstdlib>
#include <math.h>
#include <time.h>

using namespace std;

struct Node
{
    int value;
    struct Node *left;
    struct Node *right;
};

class BinaryTree
{
private:

    struct Node *head;
    bool canDuplicate;




    void DestroyNodesRecusively(struct Node* ptr){
        cout<<ptr->value<<" "<<endl;
        if(ptr==NULL)return;
        if(ptr->left != NULL){
            DestroyNodesRecusively(ptr->left);
        }
        if(ptr->right != NULL){
            DestroyNodesRecusively(ptr->right);

        }

        delete ptr;

    }

    void AddNode(int value)
    {

        struct Node *node = new struct Node;
        node->value=value;
        node->left=NULL;
        node->right=NULL;

        if(head==NULL)
        {
            head=node;
            return;
        }

        struct Node *parentNode= NULL;
        struct Node *traveller = head;

        while(traveller!=NULL)
        {
            parentNode = traveller;
            if(traveller->value >= node->value)
            {

                traveller=traveller->left;
            }
            else
            {

                traveller = traveller->right;
            }

        }


        if(parentNode->value >= node->value)
        {
            parentNode->left=node;
        }
        else
        {
            parentNode->right=node;
        }
       // parentNode = balance(parentNode);


    }

    void PrintTreeRecursive(struct Node *traveller)
    {

        if(traveller==NULL)
        {
            return;
        }
        else
        {
            PrintTreeRecursive(traveller->right);
            PrintTreeRecursive(traveller->left);
            cout<<traveller->value<<" ";
        }
    }
    int height(struct Node *temp)
    {
        int h = 0;
        if (temp != NULL)
        {
            int l_height = height (temp->left);
            int r_height = height (temp->right);
            int max_height = max (l_height, r_height);
            h = max_height + 1;
        }
        return h;
    }





public:
     int nodeCount=0;
     void DestroyNodes(){
         DestroyNodesRecusively(head);
    }



    BinaryTree()
    {
        head=NULL;
        canDuplicate=false;

    }

    void display(Node *ptr, int level)
    {
        int i;
        if (ptr!=NULL)
        {
            display(ptr->right, level + 1);
            cout<<endl;
            if (ptr == head)
            cout<<"Root -> ";
            for (i = 0; i < level && ptr != head; i++)
                cout<<"        ";
            cout<<ptr->value;
            display(ptr->left, level + 1);
        }
    }

    void CanDuplicate(bool value)
    {
        canDuplicate=value;
    }

    bool AddValue(int value)
    {

        if(canDuplicate)
        {
            AddNode(value);
        }
        else
        {

            if(IsExist(value))
            {
                cout<<"Duplicate is Off. '"<<value<<"' can not insert"<<endl;
                return false;
            }
            AddNode(value);
        }
        this->nodeCount++;
        return true;

    }

    bool IsExist(int value)
    {
        struct Node *traveller = head;
        if(traveller == NULL)
        {

        }
        while(traveller != 0)
        {

            if(traveller->value == value)
            {

                return true;
            }
            else
            {
                if(traveller->value > value)
                {
                    traveller = traveller->left;

                }
                else
                {

                    traveller = traveller->right;

                }
            }
        }
        return false;


    }


    void PrintTree()
    {
        struct Node *traveller =head;

        PrintTreeRecursive(traveller);
    }

    void PrintTreeView(){
        display(head,1);
    }




    float averadgeOfDepth(){

        float sum = sumRecusriveDepth(head,1);
        return sum/this->nodeCount;


    }

    float sumRecusriveDepth(struct Node *head,int depth){
        if(head==NULL)return 0;

        else{
            return (sumRecusriveDepth(head->left,depth+1)+sumRecusriveDepth(head->right,depth+1)+depth);
        }
    }


};



int main()
{


    int repeatCount;
    int nodeCount;
    srand (time(NULL));
    cout<<"tekrar sayısını giriniz: ";
    cin>>repeatCount;

    cout<<"Dugum sayisini giriniz :";
    cin>>nodeCount;

    for(int i =0; i<repeatCount; i++){
             BinaryTree tree;
        for(int j=0;j<nodeCount;j++){

            tree.CanDuplicate(true);
            int v = rand() % 100+1;
            tree.AddValue(v);

        }
        //tree.PrintTree();
        double av=tree.averadgeOfDepth();
        cout<<"\tAveragde of depth:"<<av<<endl;


    }

    cout<<"Logn complexity result for "<<nodeCount<<" is:\t"<<log2(nodeCount)<<endl;



    return 0;
}
