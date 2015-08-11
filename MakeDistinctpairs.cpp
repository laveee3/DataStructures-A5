// definition of MakeDistinctMirrorPairs of Assignment 5 Part 1
void MakeDistinctMirrorPairs(Node*& headPtr)
{
	int length = FindListLength(headPtr);

	if (length == 0)
		return;

	if (length == 1)
	{
		InsertAsTail(headPtr, headPtr->data);
	}

	int duplicates = 0;
   Node *cur = headPtr->link, *pre = headPtr, *temp = 0;
	for (int i = 0; i < length ; i++)
	{
		int target = pre->data;
		cout << "pre:" << pre->data << endl;
		cout << "cur:" << cur->data << endl;	
		cout << "--------------" << endl;
		while (cur->link != 0)
		{
		   if (target == cur->data)
				duplicates++;
			if (duplicates > 1)
			{
				temp = cur->link;
				delete cur;
				cur = temp;
				pre->link = cur;
			}
		   pre = cur;
		   cur = cur->link;
			cout << "pre:" << pre->data << endl;
			cout << "cur:" << cur->data << endl;	
		}
//	   pre = cur;
//	   cur = cur->link;		
	}

//
	for (int i = length; i >= 1; i--)
	{
		int j = 0, temp = 0;
		Node *cur = headPtr;
		while (cur->link != 0)
		{
			j++;
			cout << "cur->link " << cur->link->data << endl;
			if (j == i){
				temp = cur->data;
				cout << "j  " << j << endl;
				cout << "i  " << i << endl;	
				cout << cur->data << endl;
			}
			cur = cur->link;
		}
		InsertAsTail(headPtr, temp);
	}
}


//-----------------------------------------------
void MakeDistinctMirrorPairs(Node*& headPtr)
{
// when the list is empty
	if (FindListLength(headPtr) == 0)
		return;
// when the list has one node
	if (FindListLength(headPtr) == 1)
	{
		InsertAsTail(headPtr, headPtr->data);
	}

	Node *outCur = headPtr, *inCur = headPtr, *pre = 0;
	int duplicate = 0;

// deleting second or more duplicates and duplicating distinct numbers once
	while (outCur != 0)
	{
		while (inCur != 0)
		{
			if (outCur->data == inCur->data)
				duplicate++;

			if (duplicate > 2)
			{
				pre->link = inCur->link;
				delete inCur;
				inCur = pre->link;
			}		

			pre = inCur;
			inCur = inCur->link;
		}

		if (duplicate <= 1)
		{
			InsertAsTail(headPtr, outCur->data);
		}
		
		outCur = outCur->link;
		inCur = headPtr;
		pre = 0;
		duplicate = 0;
	}	

//making the first half of the linked list with distinct numbers in the same 
//order of occurence, just moving the duplicates to the last half of the linked list
	inCur = headPtr;
	outCur = headPtr;
	pre = 0;
	duplicate = 0;
	int midLength = FindListLength(headPtr)/2;

	for (int i = 1; i <= midLength; i++)
	{
		for (int j = 1; j <= midLength; j++)
		{
			if (outCur->data == inCur->data)
				duplicate++;
			
			if (duplicate > 1)
			{
				pre->link = inCur->link;
				InsertAsTail(headPtr, inCur->data);
			}

			if (duplicate <= 1)
			{			
				pre = inCur;
				inCur = inCur->link;
			}
		}
		outCur = outCur->link;
		inCur = headPtr;
		pre = 0;
		duplicate = 0;
	}

//rearranging the second half(duplicates) such that it is the mirror image of first half
	inCur = headPtr;
	outCur = headPtr;
	pre = 0;
	int j = midLength + 1, k = 0;
	duplicate = 0;

	for (int i = 1; i <= midLength; i++)
	{
		pre = 0;
		inCur = headPtr;
		for (int q = 1; q <= (midLength); q++)
		{
			pre = inCur;
			inCur = inCur->link;
		}
		cout << "inCur->data " << inCur->data << endl;
		Node *rpre = pre, *rcur = inCur, *temp = 0, *rtemp = 0;

		while (duplicate == 0)
		{
			if (outCur->data == inCur->data)
			{
				duplicate++;
				k = ((2*midLength) - i + 1);
				if (j != k)
				{
					temp = inCur;
					for (int m = midLength + 1; m < k; m++)
					{
						rpre = rcur;
						rcur = rcur->link;
					}
					rtemp = rcur;
					Node *ntemp = rtemp->link;
					pre->link = rtemp;
					rtemp->link = temp->link;
					rpre->link = temp;
					temp->link = ntemp;
					inCur = rtemp;
					rcur = temp;
				}
				//ShowAll(cout, headPtr);
				cout << "rehvah" << endl;
			}
			else
			{
				pre = inCur;
				inCur = inCur->link;
				j++;
			}
		}

		outCur = outCur->link;
		j = midLength + 1;
		duplicate = 0;
	}
	cout << "ddddddddd" << endl;
}

/////////////////////////LATEST///////////////////////////////////////////////////
//rearranging the second half(duplicates) such that it is the mirror image of first half
	inCur = headPtr;
	outCur = headPtr;
	pre = 0;
	int j = midLength + 1, k = 0;
	duplicate = 0;

	for (int i = 1; i <= midLength/2; i++)
	{
		pre = 0;
		inCur = headPtr;
		for (int q = 1; q <= (midLength); q++)
		{
			pre = inCur;
			inCur = inCur->link;
		}
		cout << "outCur " << outCur->data << "	 ";
		cout << "i " << i << "		";
		cout << "inCur->data " << inCur->data << "	";
		Node *rpre = pre, *rcur = inCur, *temp = 0;

		while (duplicate == 0)
		{
			if (outCur->data == inCur->data)
			{
				cout << "match found" << "	";
				duplicate++;
				k = ((2*midLength) - i + 1);
				cout << "k-j  " << k-j << endl;
				if (j != k && ((k-j) < (-1) || (k-j) > (1)))
				//if (j != k)
				{
					for (int m = midLength + 1; m < k; m++)
					{
						rpre = rcur;
						rcur = rcur->link;
					}
					temp = rcur->link;
					pre->link = rcur;
					rcur->link = inCur->link;
					rpre->link = inCur;
					inCur->link = temp;
					cout << "inside new loop" << "	";
					ShowAll(cout, headPtr);
				}
				if (j != k && ((k-j) == 1 || (k-j) == (-1) ))
				{
					temp = inCur->link->link;
					cout << "temp->data" << temp->data << endl;
					pre->link = inCur->link;
					cout << "pre->link->data" << pre->link->data << endl;
					pre->link->link = inCur;
					cout << "pre->link->link->data" << pre->link->link->data << endl;
					inCur->link = temp;
					cout << "inCur->link->data" << inCur->link->data << endl;
					cout << "k-j=1" << "	";
					ShowAll(cout, headPtr);
				}
				ShowAll(cout, headPtr);
			}
			else
			{
				cout << "NO match" << "	";
				pre = inCur;
				inCur = inCur->link;
				j++;
			}
			ShowAll(cout, headPtr);
			delete temp;
		}
		ShowAll(cout, headPtr);

		outCur = outCur->link;
		j = midLength + 1;
		duplicate = 0;
	}
	cout << "end" << endl;
}

