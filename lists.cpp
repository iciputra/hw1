
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


struct Item{
 Item(int v, Item* n){
 	val = v;
 	next = n;
 }
 int val;
 Item* next;
};


Item* concatenate(Item* head1, Item* head2);
Item* concat_helper(Item* head);
void removeEvens(Item*& head); 
void helper_rm (Item*& head);
Item* helper_connect (Item*& head);
double findAverage(Item* head);
int helper_sum(Item* head);
int helper_total(Item* head);
void print_out(Item* head, ofstream& out);
Item* delete_list(Item* head);

int main(int argc, char* argv[]){

	if (argc < 3){
		cout << "Error: Need both an input and output file given.\n";
		return 1;
	}

	ifstream input(argv[1]);
	if (input.fail() ){
		cout << "Unable to open file: " << argv[1] << endl;
		return 1;
	}

	ofstream output(argv[2]);
	if (output.fail() ){
		cout << "Unable to open file: " << argv[2] << endl;
		return 1;
	}

	string list1, list2;
	stringstream l1, l2;

	getline(input, list1);
	getline(input, list2);
	l1 << list1;
	l2 << list2;

	int num;
	l1 >> num;
	Item* l1_head = new Item(num, NULL);
	Item* l1_temp = l1_head;
	Item* l1_tail;

	while (l1 >> num){
		l1_tail = new Item(num, NULL);
		l1_temp->next = l1_tail;
		l1_temp = l1_tail;
	}

	int num2;
	l2 >> num2;
	Item* l2_head = new Item(num2, NULL);
	Item* l2_temp = l2_head;
	Item* l2_tail;

	while (l2 >> num2){
		l2_tail = new Item(num2, NULL);
		l2_temp->next = l2_tail;
		l2_temp = l2_tail;
	}

	Item* list3_ptr = concatenate(l1_head, l2_head);
	print_out(list3_ptr, output);

	removeEvens(list3_ptr);
	print_out(list3_ptr, output);

	double avg = findAverage(list3_ptr);
	print_out(list3_ptr, output);
	output << avg << endl;

	l1_head = delete_list(l1_head);
	l2_head = delete_list(l2_head);
	list3_ptr = delete_list(list3_ptr);
	delete list3_ptr;
	delete l1_head, l2_head, l1_temp, l2_temp, l2_tail, l1_tail;

	input.close();
	output.close();

return 0;

}



Item* concatenate(Item* head1, Item* head2){
	Item* head3 = new Item(head1->val, head1->next);
	Item* temphead = concat_helper(head1->next); 
	Item* temphead2 = new Item(head2->val, head2->next);
	temphead->next = temphead2;
	concat_helper(head2->next);
	return head3;
}

Item* concat_helper(Item* head){
	if (head -> next == NULL){
		new Item(head->val, NULL);
		return head;
	}
	else {
		new Item(head->val, head->next);
		return concat_helper(head->next);
	}
}



void removeEvens(Item*& head){
	if (head == NULL){}
	else {
		if (head->val%2 == 0){
			helper_rm(head);
			removeEvens(head); 
		}
		if (head->next != NULL){
			if (head->next->val%2 == 0){
				head->next = helper_connect(head->next);
			}
		}
		else{
			removeEvens(head->next);
		}
	}
}

void helper_rm (Item*& head){
	if (head->next != NULL){
		Item* temphead = head;
		head = head->next;
		delete temphead;
	}
	else {
		delete head;
	}
}

Item* helper_connect (Item*& head){
	if (head == NULL){
		return NULL;
		}
	else {
		if (head->next->val % 2 == 0){ 
			if (head->next->next == NULL){ 
				Item* temphead = head->next;
				head->next = NULL;
				helper_rm(temphead);
				return NULL;
			}
			else { 
				Item* temphead = helper_connect(head->next); 
				helper_rm(head); 
				return temphead;
			}
		}
		else {
			Item* temphead = head->next;
			helper_rm(head);
			return temphead;
		}
	} 
}



double findAverage(Item* head){
	int sum = helper_sum(head); 
	int total = helper_total(head);
	double avg = 1.0*sum/total;
	return avg;
}

int helper_sum(Item* head){
	if (head == NULL) { return 0; }
	else { return helper_sum(head->next) + head->val; }
}

int helper_total(Item* head){
	if (head == NULL) { return 0; }
	else { return helper_total(head->next) + 1; }	
}

void print_out (Item* head, ofstream& out){
	Item* temp_head = head;
	int counter = 0;
	while (temp_head != NULL){
		int value = temp_head->val;
		out << value << " ";
		temp_head = temp_head-> next;
		counter++;
	}
	out << endl;
}

Item* delete_list(Item* head){
	if (head == NULL){
	return NULL;
	}
	else{
	delete_list(head->next);
	delete head;
	return NULL;
	}
}