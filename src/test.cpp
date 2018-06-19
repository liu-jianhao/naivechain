#include "block.h"

using namespace std;

int main()
{
    initBlockChain();

    Block* my_block = generateNextBlock("my first block");
    cout << my_block->Hash << endl;
    cout << isValidNewBlock(BlockChain.back(), my_block) << endl;
    return 0;
}
