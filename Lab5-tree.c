#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {
char data[20];
struct node* child;
struct node* sibling;
}*root=NULL;
int checkval=0;
int frequency=1;
//insert category
void insertCategory(struct node* root,char* ch,int x){
	if(x==0){
	if(root->child == NULL){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->child=NULL;
		temp->sibling=NULL;
		root->child=temp;
		printf("\n Category inserted\n\n");
	}
	else{
		root=root->child;
		while(root->sibling != NULL){
		if(strcmp(root->data,ch) == 0){
			printf("\nCategory already exists\n\n");
			return;
		}
		root=root->sibling;
		}
		if(strcmp(root->data,ch) == 0){
			printf("\nCategory already exists\n\n");
			return;
		}
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->child=NULL;
		temp->sibling=NULL;
		root->sibling=temp;
		printf("\n Category inserted\n\n");
	}
	}
	else{
	if(root->child == NULL){
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->child=NULL;
		temp->sibling=NULL;
		root->child=temp;
		printf("\n word inserted\n\n");
	}
	else{
		root=root->child;
		while(root->sibling != NULL){
		if(strcmp(root->data,ch) == 0){
			if(root->child == NULL){
				struct node* freq=(struct node*)malloc(sizeof(struct node));
				strcpy(freq->data,"2");
				checkval=1;
				if(2 > frequency){
					frequency=2;
				}
				freq->child=NULL;
				freq->sibling=NULL;
				root->child=freq;
				printf("\nFrequency updated\n\n");
				return;
			}
			else{
				char c1=root->child->data[0];
				int x=c1-'0';
				x=x+1;
				if(x > frequency){
					frequency=x;
				}
				c1=x+'0';
				root->child->data[0]=c1;
				printf("\nFrequency updated\n\n");
				return;
			}
		}
		root=root->sibling;
		}
		if(strcmp(root->data,ch) == 0){
			if(root->child == NULL){
				struct node* freq=(struct node*)malloc(sizeof(struct node));
				strcpy(freq->data,"2");
				checkval=1;
				if(2 > frequency){
					frequency=2;
				}
				freq->child=NULL;
				freq->sibling=NULL;
				root->child=freq;
				printf("\nFrequency updated\n\n");
				return;
			}
			else{
				char c1=root->child->data[0];
				int x=c1-'0';
				x=x+1;
				if(x > frequency){
					frequency=x;
				}
				c1=x+'0';
				root->child->data[0]=c1;
				printf("\nFrequency updated\n\n");
				return;
			}
		}
		struct node* temp=(struct node*)malloc(sizeof(struct node));
		strcpy(temp->data,ch);
		temp->child=NULL;
		temp->sibling=NULL;
		root->sibling=temp;	
		printf("\n word inserted\n\n");
	}
}
}
int countofDegree(struct node* root){
	int c=0;
	while(root!=NULL){
		c+=1;
		root=root->sibling;
	}
	return c;
}
int wordcheck=0;
void Descendingorder(struct node* root,int freq){
	while(root!=NULL){
		struct node* check=(struct node*)malloc(sizeof(struct node*));
		check=root->child;
		while(check!=NULL){
			if(check->child!=NULL){
				char ch=check->child->data[0];
				int value=ch-'0';
				if(value==freq){
					printf("%s - %d\n",check->data,freq);
					wordcheck=1;
				}
			}
			else if(check->child==NULL && freq==1){
				printf("%s\n",check->data);
				wordcheck=1;
		}
		check=check->sibling;
	}
	root=root->sibling;	
}
}
int countofDepth(struct node* root){
	int c=0,maxv=0;
	while(root!=NULL){
	struct node* temp=root;
	c=0;
	while(temp!=NULL){
		c+=1;
		temp=temp->child;
	}
	if(c>maxv)
	maxv=c;
	root=root->sibling;
	}
	return maxv;
}
int degree=0;
void Degree(struct node* root, char* ch){
	if(root==NULL)
	return;
	if(strcmp(root->data,ch)==0){
		printf("\nDegree is %d\n\n",countofDegree(root->child));
		degree=1;
	return ;
	}
	else{
		Degree(root->child,ch);
		Degree(root->sibling,ch);
	}
}
int depth=0;
void Depth(struct node* root, char* ch){ 
	if(root==NULL)
	return ;
	if(strcmp(root->data,ch)==0){
		printf("\nDepth is %d\n\n",countofDepth(root->child));
		depth=1;
	return ;
	}
	else{
		Depth(root->sibling,ch);
		Depth(root->child,ch);	
	}
}

void display(struct node* root){
	printf("\n%s\n",root->data);
	root=root->child;
	while(root!=NULL){
		printf("\nCategory:\n");
		printf("%s\n",root->data);
		struct node* temp=root;
		temp=temp->child;
		printf("words:\n");
		if(temp==NULL)
		printf("empty\n");
		else{
		while(temp!=NULL){
			printf("%s",temp->data);
			if(temp->child != NULL){
				printf(" %s\n",temp->child->data);
			}
			else{
				printf("\n");
			}
			temp=temp->sibling;
		}
	}
		root=root->sibling;
	}
	printf("\n");
}
void displayleaf(struct node* root){
	while(root!=NULL){
	struct node* temp=root->child;
	if(temp==NULL){
		printf("%s\n",root->data);
	}
	else{
	while(temp!=NULL){
		printf("%s\n",temp->data);
		temp=temp->sibling;
	}
	}
	root=root->sibling;
}
printf("\n");
}
void insertwords(struct node *root,char* ch,char* cat){
	if(root->child == NULL){
		printf("\n\nNo Category Exists\n\n");
		return;
	}
	else{
		root=root->child;
		while(root!= NULL){
		if(strcmp(root->data,cat) == 0){
			break;
		}
		root=root->sibling;
		}
		if(root==NULL){
			printf("\nNo such category found\n\n");
			return;
		}
		else{
		insertCategory(root,ch,1);
	}
}
}
int main(){
struct node* temp=(struct node*)malloc(sizeof(struct node));
char ch[]="words";
strcpy(temp->data,ch);
temp->child=NULL;
temp->sibling=NULL;
root=temp;
int choice=0;
while (choice!=8)
    {
printf("Enter your choice :\n1.Insert Category 2.Insert word 3.Display 4.Display Leaf nodes 5. Degree 6.Depth 7.Frequency Descending order 8.Exit: ");    
        if(scanf("%d", &choice)==1){
        if(choice==1){
        	fflush(stdin);
        	char ch[20];
        	printf("Enter the Category: ");
        	gets(ch);
        	insertCategory(root,ch,0);
			}
		else if(choice==2){
			if(root->child == NULL)
			printf("\nCategories are empty\n\n");
			else{
			fflush(stdin);
        	char ch[20];
        	printf("Enter the word: ");
        	gets(ch);
        	fflush(stdin);
        	char cat[20];
        	printf("Enter the Category: ");
        	gets(cat);
        	insertwords(root,ch,cat);
		}
	}
		else if(choice==3){
			display(root);
		}
		else if(choice==4){
			printf("\nLeaf nodes:\n");
			if(root->child==NULL)
			printf("%s\n\n",root->data);
			else
			displayleaf(root->child);
		}
		else if(choice==5){
			printf("Enter the word/category: ");
			fflush(stdin);
        	char w[20];
        	gets(w);
        	Degree(root,w);
        	if(degree==0)
        	printf("\nNo such word found\n\n");
        	degree=0;
		}
		else if(choice==6){
			printf("Enter the word/category: ");
			fflush(stdin);
        	char x[20];
        	gets(x);
        	if(strcmp(x,"words")==0 && checkval==1){
        		printf("\nDepth is 3\n\n");
			}
			else{
        	Depth(root,x);
        	if(depth==0)
        	printf("\nNo such word found\n\n");
        	depth=0;
        }
		}
		else if(choice==7){
			if(root->child == NULL){
				printf("\nNo words Exist\n\n");
			}
			else{
			printf("\n");
			int p=frequency;
			while(p>0){
			Descendingorder(root->child,p);
			p--;
			}
			if(wordcheck==0)
			printf("No words exist\n");
			printf("\n");	
		}
		}
		else if(choice==8)
		break;
		else
			printf("\nEnter valid choice\n\n");
}
else{
	printf("\nEnter Numbers only\n");
	exit(0);
}
}
}

