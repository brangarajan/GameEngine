#ifndef PCSTREE_H
#define PCSTREE_H

// Simple data structure
struct PCSTreeInfo
{
   int currNumNodes;
   int maxNumNodes;
   int currNumLevels;
   int maxNumLevels;
};

// forward declare
class PCSNode;

// PCSTree class 
class PCSTree
{
public:
   // constructor
   PCSTree();

   // destructor
   ~PCSTree();

   // get Root
   PCSNode *getRoot( void ) const;

   // insert
   void insert(PCSNode * const inNode, PCSNode * const parent);

   // remove
   void remove(PCSNode * const inNode);

   // get info
   void getInfo( PCSTreeInfo &info );
   void printTree( ) const;   

private:
   // copy constructor 
   PCSTree( const PCSTree &in );

   // assignment operator
   PCSTree & operator = (const PCSTree &in);

   // Data
   PCSTreeInfo mInfo;
   PCSNode     *root;

   PCSNode * privateSetPCS(PCSNode * node, PCSNode *parent, PCSNode *child, PCSNode *sibling) const;
   void privateUpdateAddNode(void);
   void privateUpdateAddLevel(PCSNode * node);
   void privateRemoveHelperSib(PCSNode * node) const;
   void privateRemoveHelperChild(PCSNode * node) const;
   void privateUpdateRedoLevelCount(PCSNode *node);
   void privatePrintTree(PCSNode *node) const;
};



#endif