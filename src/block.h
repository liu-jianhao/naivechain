#ifndef __BLOCK_H
#define __BLOCK_H

#include <string>
#include <list>
#include <iostream>
#include <time.h>
#include "../dep/PicoSHA2/picosha2.h"

using namespace std;

/* 一个区块 */
struct Block{
    int index;              //区块哈希
    string previousHash;    //前一个区块的哈希
    time_t timestamp;       //时间戳
    string data;            //区块数据
    string Hash;            //区块哈希
};


/* 区块链 */
list<Block*> BlockChain;

/* 创世区块 */
void initBlockChain()
{
    Block *genesisBlock = new Block();
    genesisBlock->index = 0;
    genesisBlock->previousHash = "0";
    genesisBlock->timestamp = 1465154705;
    genesisBlock->data = "my genesis block!!";
    genesisBlock->Hash = "816534932c2b7154836da6afc367695e6337db8a921823784c14378abed4f7d7";
    BlockChain.push_back(genesisBlock);
}


/* 计算新区块的哈希 */
string calculateHashForBlock(Block* b)
{
    return picosha2::hash256_hex_string(to_string(b->index) + b->previousHash + to_string(b->timestamp) + b->data);
}

/* 获得区块链上最新的一个区块 */
Block* getLatestBlock()
{
    return BlockChain.back();
}


/* 产生一个新区快 */
Block* generateNextBlock(string data)
{
    Block *previousBlock = getLatestBlock();
    Block *newBlock = new Block();
    newBlock->data = data;
    newBlock->previousHash = previousBlock->Hash;
    newBlock->index = previousBlock->index + 1;
    time_t timep;
    time(&timep);
    newBlock->timestamp = timep;
    newBlock->Hash = calculateHashForBlock(newBlock);
    return newBlock;
}

/* 验证区块的完整性，完整返回1，不完整返回0 */
int isValidNewBlock(Block* pb, Block* nb)
{
    if(nb->Hash == calculateHashForBlock(nb) && pb->index+1 == nb->index && pb->Hash == nb->previousHash)
        return 1;
    return 0;
}


#endif
