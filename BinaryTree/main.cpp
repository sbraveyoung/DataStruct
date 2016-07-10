void test1()
{
    int pre[]={1,2,4,8,9,5,10,3,6,7};
    int in[]={8,4,9,2,10,5,1,6,3,7};
    int post[]={8,9,4,10,5,2,6,7,3,1};
    BinaryTree<int> btree;
    //btree.CreateWithPre(pre,in,sizeof(pre)/sizeof(pre[0]));
    btree.CreateWithPost(post,in,sizeof(post)/sizeof(post[0]));
    btree.PreOrder();
    btree.InOrder();
    btree.PostOrder();
    btree.PreOrder_NR();
    btree.InOrder_NR();
    btree.PostOrder_NR();
    btree.LevelOrder();
    cout<<btree.Depth()<<endl;
    btree.PrintEdge1();
}

void test2()
{
    int pre[]={1,2,4,7,8,11,13,14,3,5,9,12,15,16,10,6};
    int in[]={2,7,4,8,13,11,14,1,15,12,16,9,5,10,3,6};
    BinaryTree<int> btree;
    btree.CreateWithPre(pre,in,sizeof(pre)/sizeof(pre[0]));
    //btree.PrintEdge1();
    //btree.PrintEdge2();
    //btree.PrintTree();
    btree.MorrisIn();
    btree.MorrisPre();
    btree.MorrisPost();
}


int main()
{
    //test1();
    test2();
}
