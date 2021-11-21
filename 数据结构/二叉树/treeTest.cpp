# include <stdio.h>
# include "tree.h"
int main(void)
{
	treenode *n;
	n=create();
	midorder(n);
	
	
	return 0;
}
