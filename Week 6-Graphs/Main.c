#include<stdio.h>
#include<stdlib.h>

// Number of persons (or vertices in the graph)
#define N 3

int** update_graph(int graph[][N])
{
    int i,j,num;
    printf("Enter the number of guy who has to pay: ");
    scanf("%d", &i);
    printf("Enter the number of guy to deal with: ");
    scanf("%d",&j);
    printf("Enter the amount guy %d has to pay to guy %d : ",i,j );     
    scanf("%d" , &num);
    
    graph[i][j]=num;
    return graph;
}

// display 2D array using for loop
void display_graph(int graph[][N])
{
  printf("\n The Array elements are:\n");

    // outer loop for row
    for(int i=0; i<N; i++)
    {
        // inner loop for column
        for(int j=0; j<N; j++)
        {
            printf("%d ", graph[i][j]);
        }
    printf("\n"); // new line
    }
}


// A utility function that returns index of minimum value in arr[]
int getMin(int arr[])
{
	int minInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] < arr[minInd])
			minInd = i;
	return minInd;
}

// A utility function that returns index of maximum value in arr[]
int getMax(int arr[])
{
	int maxInd = 0;
	for (int i=1; i<N; i++)
		if (arr[i] > arr[maxInd])
			maxInd = i;
	return maxInd;
}

// A utility function to return minimum of 2 values
int minOf2(int x, int y)
{
	return (x<y)? x: y;
}

// amount[p] indicates the net amount to be credited/debited
// to/from person 'p'
// If amount[p] is positive, then i'th person will amount[i]
// If amount[p] is negative, then i'th person will give -amount[i]

void minCashFlowRec(int amount[])
{
	// Find the indexes of minimum and maximum values in amount[]
	// amount[mxCredit] indicates the maximum amount to be given
	//				 (or credited) to any person .
	// And amount[mxDebit] indicates the maximum amount to be taken
	//				 (or debited) from any person.
	// So if there is a positive value in amount[], then there must
	// be a negative value
	int mxCredit = getMax(amount), mxDebit = getMin(amount);

	// If both amounts are 0, then all amounts are settled
	if (amount[mxCredit] == 0 && amount[mxDebit] == 0)
		return;

	// Find the minimum of two amounts
	int min = minOf2(-amount[mxDebit], amount[mxCredit]);
	amount[mxCredit] -= min;
	amount[mxDebit] += min;

	// If minimum is the maximum amount to be
	printf("Person %d pays %d to Person %d\n", mxDebit, min, mxCredit);

	// Recur for the amount array. Note that it is guaranteed that
	// the recursion would terminate as either amount[mxCredit]
	// or amount[mxDebit] becomes 0
	minCashFlowRec(amount);
}

// Given a set of persons as graph[] where graph[i][j] indicates
// the amount that person i needs to pay person j, this function
// finds and prints the minimum cash flow to settle all debts.
void minCashFlow(int graph[][N])
{
	// Create an array amount[], initialize all value in it as 0.
	int amount[N] = {0};

	// Calculate the net amount to be paid to person 'p', and
	// stores it in amount[p]. The value of amount[p] can be
	// calculated by subtracting debts of 'p' from credits of 'p'
	for (int p=0; p<N; p++)
	for (int i=0; i<N; i++)
		amount[p] += (graph[i][p] - graph[p][i]);

	minCashFlowRec(amount);
}

// Driver program to test above function
void main()
{
    int graph[N][N];
    int a;
    int b;
    
    int choice;
    
    while(1){                  //printing choices for the user                      
        printf("\nEnter 1 to create a graph problem. ");
        printf("\nEnter 2 to update the graph. ");
        printf("\nEnter 3 to display the graph. ");
        printf("\nEnter 4 to print the solution. ");
        printf("\nEnter 5 to exit: ");
        printf("\n \nEnter your choice: \n");
        scanf("%d",&choice);
        
        // Switch case
        switch (choice) {
            
            case 1:
                    for (a=0; a<N; a++){
                        for (b=0; b<N; b++){
                            printf("Enter the amount guy %d has to pay to guy %d : ",a,b );            
                            scanf("%d",&graph[a][b]);
                        }
                    }
                    break;
                     
            case 2:
                    
                    update_graph(graph);
                    break;         
                    
            case 3:
                    //Calling function to Display the records
                    display_graph(graph);
                    break;
                
            case 4:
                    // Print the solution
                	minCashFlow(graph);
                	break;
                    
            case 5: 
                    exit(0);
        
        }    //end of switch
    }        //end of while loop
 
    
}    //end of main
  
  
  /*
  
	int graph[N][N] = { {0, 1000, 2000, 3000},
						{0, 0, 5000, 0},
						{0, 0, 0, 0},
	                    {0, 0, 0, 0},
	                  };
	                  
	                  
	Person 1 pays 4000 to Person 2
    Person 0 pays 3000 to Person 2  
    

    Algorithmic Paradigm: Greedy 
Time Complexity: O(N2) where N is the number of persons.

  */