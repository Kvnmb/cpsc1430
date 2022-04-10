/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM HERE TO LINE 71***********/
#include "Helper.h"
using namespace std;

//Merge two sorted linked lists in place for task I
Node * mergeList(Node * l1Head, Node * l2Head);
//Removes all the nodes in a sorted list that have the targeted value
Node * removeTargets(Node * head, int val);
//Remove duplicatesd nodes such that node with the same value only appears once
Node * removeDuplicates(Node * head);
//Find the middle node in a given linked list
Node * findMiddle(Node * head);

//Your program will be tested with the following command:
//./lab7_8 test_case.txt NUMBER_HERE(Replace with real number),
//where lab7_8 is your executable name after compilation, 
//test_case.txt is a txt file that has two lines of numbers for creating two lists,
//NUMBER_HERE is a specific target number for task II.
//Note that (1) NUMBER_HERE can be any number when running the command.
//For example, a real command in practice could be "./lab7_8 test_case.txt 6".
//(2) lines could be empty in test_case.txt, which means empty list could be created
int main(int argc, char * argv[]){
    //Preparation. I get this done so that you can focus on the following three tasks.
    //create a list using the first line in the input file
    Node * l1Head = createListFromFile(argv[1], 1);
    //create a list using the second line in the input file
    Node * l2Head = createListFromFile(argv[1], 2);
    // printList(l1Head);
    // printList(l2Head);

    //Your task I: merge the above two sorted lists and keep the merged list sorted.
    //the merge should be in-place. That is, you are not allowed to create a new list,
    //in which node values are copied from two given lists.
    //Instead, you should change the pointers of each existing node properly 
    //to chain the existing nodes in both lists together.
    Node * listHeadAfterTaskI = mergeList(l1Head, l2Head);
    printList(listHeadAfterTaskI);

    //Your task II: find the middle node in the linked list generated after task I
    //If there are two middle nodes, return the first middle nodes.
    //For example, if the list is head->1->2->3->null, the middle node will be 2;
    //if the list is head->1->2->3->4->null, there are will be two middle 
    //nodes (i.e., 2 and 3), your function should return the *first* one, i.e., 2.
    Node * middleNode = findMiddle(listHeadAfterTaskI);
    if (middleNode){
        cout << "The value of the middle node is " << middleNode->value << endl;
    }else{
        cout << "No middle node in an empty list." << endl;
    }

    //Your task III: remove all the nodes in a sorted list that have the targeted value.
    //For example, assuming the targeted value is 6, and the merged list after task I
    //is head->2->2->6->6->7->7->7->7->8->9->null, 
    //after this task III the list will become head->2->2->7->7->7->7->8->9->null
    int targetVal = stoi(argv[2]);
    Node * listHeadAfterTaskIII = removeTargets(listHeadAfterTaskI, targetVal);
    printList(listHeadAfterTaskIII);

    //Your task IV: remove all the duplicated nodes (such that node with the same value
    // only appears once) in the merged list after task III.
    //Since the list remains sorted (non-descending) after task III, 
    //the final list will be strictly ascending as we removed all the duplicated values.
    //Continuing the previous example in taskIII, 
    //if the list returned by taskIII is head->2->2->7->7->7->7->8->9->null,
    //after this taks IV, it will become head->2->7->8->9->null
    Node * listHeadAfterTaskIV = removeDuplicates(listHeadAfterTaskIII);
    printList(listHeadAfterTaskIV);

    return 0;
}
/********* YOUR ARE NOT ALLOWED TO CHANGE ANYTHING FROM Line 1 TO HERE ***********/



/********* YOU SHOULD IMPLEMENT THREE FUNCTIONS AFTER THIS LINE **********/
Node * mergeList(Node * l1Head, Node * l2Head){
    //PUT YOUR CODE HERE FOR TASK I
    if(!l1Head && !l2Head){ // if loops to ensure the lists are valid
        return nullptr;
    }else if(!l1Head){
        return l2Head;
    }else if(!l2Head){
        return l1Head;
    }else{
        Node *l1Ptr;
        Node *l2Ptr;
        Node *nodePtr;

        nodePtr = l1Head;
        l2Ptr = l2Head;

        // this while loop will insert list 2 into list 1
        while(l2Head){ // until list 2 is empty
            l1Ptr = nodePtr; // at each iteration the loop is reset to the head
            l2Ptr = l2Head;

            // while loop to find correct positioning for the list 2 node
            while(l1Ptr != nullptr && l1Ptr->value <= l2Ptr->value){
                nodePtr = l1Ptr;
                l1Ptr = l1Ptr->next;
            }
            
            // checks if list 2 node should be first in the list
            if(l1Ptr == l1Head){
                l2Head = l2Ptr->next;
                l2Ptr->next = l1Ptr; // puts node before list 1's first node
                l1Head = l2Ptr;
                nodePtr = l2Ptr;
            // puts list 2 node at end of list 1
            }else if(l1Ptr == nullptr){
                nodePtr->next = l2Ptr;
                l2Head = l2Ptr->next;
                l2Ptr->next = nullptr;
                nodePtr = l2Ptr;
            }else{ // regular insertion
                nodePtr->next = l2Ptr;
                l2Head = l2Ptr->next;
                l2Ptr->next = l1Ptr;
                nodePtr = l2Ptr;
            }
        }
        return l1Head;
    }
}

Node * findMiddle(Node * head){
    //PUT YOUR CODE HERE FOR TASK II
    if(!head){ // checks for empty list
        return nullptr;
    }else{
        Node *middleNode = head;
        Node *nodePtr = middleNode->next;
        int counter = 1;

        while(nodePtr != nullptr){ // loop to keep middleNode in the middle of
        // the list as it is traversing
            if((counter % 2) == 0){
                middleNode = middleNode->next;
            }
            nodePtr = nodePtr->next;
            counter++;
        }
        return middleNode;
    }
}

Node * removeTargets(Node * head, int val) {
    //PUT YOUR CODE HERE FOR TASK III
    if(!head){
        return nullptr;
    }else{
        Node *nodePtr = head;
        Node *prev = nullptr;

        while(nodePtr){
            if(nodePtr->value == val){
                if(nodePtr == head){ // checks if value to be deleted is head
                    head = nodePtr->next;
                    prev = nodePtr;
                    nodePtr = nodePtr->next;
                    delete prev;
                    prev = nullptr;
                }else{ // regular delete
                    prev->next = nodePtr->next;
                    delete nodePtr;
                    nodePtr = prev->next;
                }
            }else{ // traverses list
                prev = nodePtr;
                nodePtr = nodePtr->next;
            }
        }
        return head;
    }
}

Node * removeDuplicates(Node * head) {
    //PUT YOUR CODE HERE FOR TASK IV
    if(!head){
        return nullptr;
    }else{
        Node *nodePtr;
        Node *nextPtr;

        nodePtr = head;
        nextPtr = nodePtr->next;

        while(nextPtr != nullptr){
            // if loop checks if the value of the node after nodePtr is the
            // same, and if so deletes that node
            if(nodePtr->value == nextPtr->value){
                nodePtr->next = nextPtr->next;
                delete nextPtr;
                nextPtr = nodePtr->next;
            }else{ // traverses list
                nodePtr = nextPtr;
                nextPtr = nextPtr->next;
            }
        }
        return head;
    }
}

