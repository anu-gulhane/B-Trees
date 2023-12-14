#include "InternalNode.hpp"
#include "Logger.hpp"
#include "LeafNode.hpp"
#include "RecordPtr.hpp"
//creates internal node pointed to by tree_ptr or creates a new one
InternalNode::InternalNode(const TreePtr &tree_ptr) : TreeNode(INTERNAL, tree_ptr) {
    this->keys.clear();
    this->tree_pointers.clear();
    if (!is_null(tree_ptr))
        this->load();
}

//max element from tree rooted at this node
Key InternalNode::max() {
    Key max_key = DELETE_MARKER;
    TreeNode* last_tree_node = TreeNode::tree_node_factory(this->tree_pointers[this->size - 1]);
    max_key = last_tree_node->max();
    delete last_tree_node;
    return max_key;
}

//if internal node contains a single child, it is returned
TreePtr InternalNode::single_child_ptr() {
    if (this->size == 1)
        return this->tree_pointers[0];
    return NULL_PTR;
}
// INSERT
//inserts <key, record_ptr> into subtree rooted at this node.
//returns pointer to split node if exists
//TODO: InternalNode::insert_key to be implemented
TreePtr InternalNode::insert_key(const Key &key, const RecordPtr &record_ptr) {
    logger.log("internal node insert keyy");
    TreePtr new_tree_ptr = NULL_PTR;
    // cout << "InternalNode::insert_key not implemented" << endl;
    TreePtr nextTreePtr;
    int n=this->keys.size();
    logger.log("internode number of keys"+to_string(n));
    int index;
    for(auto each:this->keys)
    {
        logger.log("keys : "+to_string(each));
    }
    if(key<=this->keys[0])
    {   
        nextTreePtr=this->tree_pointers[0];
        index=0;
    }
    else if(this->keys[n-1]<key)
    {
        nextTreePtr=this->tree_pointers.back();
        index=n;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(key<=this->keys[i])
            {
                nextTreePtr=this->tree_pointers[i];
                index=i;
                break;
            }
        }
    }
    logger.log("next node pointer index "+ to_string(index));
    TreeNode*node=TreeNode::tree_node_factory(nextTreePtr);
    logger.log("before insert function in the next node");
    TreePtr potential_split_node_ptr = node->insert_key(key, record_ptr);
    logger.log("after insert function in the next node");
    if(!is_null(potential_split_node_ptr))
    {
        logger.log("leaf is splitted");
        auto new_node = TreeNode::tree_node_factory(potential_split_node_ptr);
        Key newKey=node->max();
        logger.log("key to be added in the internal node "+to_string(newKey));
        this->keys.insert(this->keys.begin()+index,newKey);
        logger.log("size "+to_string(this->size));
        logger.log("sd "+to_string(this->keys.size()));
        //check whether this is correct or not
        this->tree_pointers.insert(this->tree_pointers.begin()+(index+1),potential_split_node_ptr);
        this->size++;
        logger.log("internal node size "+to_string(this->size));
        if(this->keys.size()>FANOUT)
        {
            logger.log("internal node is full");
            auto new_internal_node = new InternalNode();
            int splitIndex=floor((float)this->size/2);
            logger.log("split index "+to_string(splitIndex));
            for(int i=0; i<this->size; i++)
            {
                if(i<splitIndex)
                    continue;
                else
                {
                    Key key=this->keys[i];
                    TreePtr treePtr=this->tree_pointers[i];
                    new_internal_node->keys.push_back(key);
                    new_internal_node->tree_pointers.push_back(treePtr);
                    // this->keys.erase(this->keys.begin()+i);
                    // this->tree_pointers.erase(this->tree_pointers.begin()+i);
                    new_internal_node->size++;

                }
            }
            int n=this->size;
            TreePtr treePtr=this->tree_pointers[n];
            new_internal_node->tree_pointers.push_back(treePtr);
            this->keys.erase(this->keys.begin()+splitIndex,this->keys.end());
            this->tree_pointers.erase(this->tree_pointers.begin()+splitIndex,this->tree_pointers.end());
            this->size=splitIndex;
            new_tree_ptr=new_internal_node->tree_ptr;
            new_internal_node->dump();
            delete new_internal_node;
        }
        // else
        // {
            
        // }
    }
    this->dump();
    logger.log("insertion to internal node is done");
    return new_tree_ptr;
}

//deletes key from subtree rooted at this if exists
//TODO: InternalNode::delete_key to be implemented
void InternalNode::delete_key(const Key &key) {
    TreePtr new_tree_ptr = NULL_PTR;
    logger.log("in the delete key function internal node");
    // cout << "InternalNode::delete_key not implemented" << endl;
    TreePtr nextTreePtr;
    int n=this->keys.size();
    logger.log("internal node number of keys"+to_string(n));
    int index;
    logger.log(to_string(this->keys[0])+ " "+to_string(this->keys[n-1]));
    if(key<=this->keys[0])
    {   
        nextTreePtr=this->tree_pointers[0];
        index=0;
    }
    else if(this->keys[n-1]<key)
    {
        nextTreePtr=this->tree_pointers.back();
        index=n;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(key<=this->keys[i])
            {
                nextTreePtr=this->tree_pointers[i];
                index=i;
                break;
            }
        }
    }
    logger.log("next node pointer index "+ to_string(index));
    TreeNode*node=TreeNode::tree_node_factory(nextTreePtr);
    logger.log("before delete function in the next node");
    node->delete_key(key);
    logger.log("node got deleted");
    if(node->node_type==LEAF)
    {
        logger.log("checking underflow conditions in leaf node");
        if(node->underflows())
        {
            logger.log("underflow occurs");
            if(index>0)
            {
                logger.log("left sibling is present");
                TreePtr leftSibling=this->tree_pointers[index-1];
                LeafNode* leftSiblingNode=(LeafNode*)TreeNode::tree_node_factory(leftSibling);
                if(leftSiblingNode->size>MIN_OCCUPANCY)
                {
                    logger.log("left sibling has more than occupancy");
                    Key key=leftSiblingNode->max();
                    logger.log("key to be shifted "+to_string(key));
                    RecordPtr recordPtr=leftSiblingNode->data_pointers[key];
                    leftSiblingNode->delete_key(key);
                    node->insert_key(key,recordPtr);
                    this->keys[index-1]=leftSiblingNode->max();
                    leftSiblingNode->dump();
                    logger.log("..done");
                }
                else
                {   LeafNode*nodeLeaf=(LeafNode*)node;
                    for(auto elem:nodeLeaf->data_pointers)
                    {
                        Key key=elem.first;
                        RecordPtr recordPtr=elem.second;
                        leftSiblingNode->insert_key(key,recordPtr);
                    }
                    leftSiblingNode->next_leaf_ptr=nodeLeaf->next_leaf_ptr;
                    delete nodeLeaf;
                    this->keys.erase(this->keys.begin()+index-1);
                    this->tree_pointers.erase(this->tree_pointers.begin()+index);
                    this->keys[index-1]=leftSiblingNode->max();
                    this->size--;
                    this->dump();
                    leftSiblingNode->dump();
                }
            }
            else
            {

                logger.log("right sibling is present");
                TreePtr rightSibling=this->tree_pointers[index+1];
                LeafNode* rightSiblingNode=(LeafNode*)TreeNode::tree_node_factory(rightSibling);
                if(rightSiblingNode->size>MIN_OCCUPANCY)
                {
                    auto elem=rightSiblingNode->data_pointers.begin();
                    Key key=elem->first;
                    RecordPtr recordPtr=elem->second;
                    rightSiblingNode->delete_key(key);
                    node->insert_key(key,recordPtr);
                    // this->keys.erase(this->keys.begin()+index);
                    this->keys[index]=node->max();
                    rightSiblingNode->dump();
                    this->dump();
                    node->dump();
                }
                else
                {   
                    logger.log("right sibling with min occupancy");
                    LeafNode*nodeLeaf=(LeafNode*)node;
                    for(auto elem:rightSiblingNode->data_pointers)
                    {
                        Key key=elem.first;
                        RecordPtr recordPtr=elem.second;
                        node->insert_key(key,recordPtr);
                    }
                    logger.log("after merging node size "+to_string(node->size));
                    nodeLeaf->next_leaf_ptr=rightSiblingNode->next_leaf_ptr;
                    delete rightSiblingNode;
                    logger.log("before erase");
                    this->keys.erase(this->keys.begin()+index);
                    this->tree_pointers.erase(this->tree_pointers.begin()+index+1);
                    logger.log("after erase");
                    logger.log(" key size after erase"+to_string(this->keys.size()));
                    if(this->keys.size()>0)
                        this->keys[index]=nodeLeaf->max();
                    this->size--;
                    logger.log("size of internal node "+to_string(this->size));
                    this->dump();
                    node->dump();
                }   
            }
        }
    }
    else
    {
        logger.log("checking underflow conditions in internal node");
        if(node->underflows())
        {
            logger.log("underflow in internal node and index is" + to_string(index));
            if(index>0)
            {
                TreePtr leftSibling=this->tree_pointers[index-1];
                InternalNode* leftSiblingNode=(InternalNode*)TreeNode::tree_node_factory(leftSibling);
                logger.log("size of left sibling is "+to_string(leftSiblingNode->size));
                if(leftSiblingNode->size>MIN_OCCUPANCY)
                {
                    logger.log("left sibling is greater than min occ");
                    Key rootKey=this->keys[index-1];
                    logger.log("root key value " +to_string(rootKey));
                    Key key=leftSiblingNode->keys.back();
                    logger.log("key to be shifted "+ to_string(key));
                    InternalNode*internalNode=(InternalNode*)node;
                    TreePtr treePtr=leftSiblingNode->tree_pointers.back();
                    leftSiblingNode->keys.erase(leftSiblingNode->keys.end()-1);
                    leftSiblingNode->tree_pointers.erase(leftSiblingNode->tree_pointers.end()-1);
                    leftSiblingNode->size--;
                    logger.log("size of left sibling "+to_string(leftSiblingNode->size));
                    internalNode->keys.insert(internalNode->keys.begin(),rootKey);
                    logger.log("after insert into keys");
                    for(auto each:internalNode->keys)
                    {
                        logger.log("keys "+to_string(each));
                    }
                    logger.log("size of internal node key size "+to_string(internalNode->size));
                    internalNode->tree_pointers.insert(internalNode->tree_pointers.begin(),treePtr);
                    logger.log("after insert into treepointers");
                    internalNode->size++;
                    logger.log("internal node size "+to_string(internalNode->size));
                    this->keys[index-1]=key;
                    logger.log("after adding keys index and string "+to_string(index-1)+ " "+to_string(this->keys[index-1]));
                    this->dump();
                    // node->dump();
                    leftSiblingNode->dump();
                    logger.log("left sibling node dumped");
                    internalNode->dump();
                    logger.log("internal node dumped");
                    delete internalNode;
                    logger.log("internal node deleted");
                    // logger.log("internal node deleted");
                }
                else
                {
                    logger.log("left sibling node is min occ");
                    Key rootKey=this->keys[index-1];
                    logger.log("root key is "+to_string(rootKey));
                    logger.log("internal node size "+to_string(leftSiblingNode->keys.size()));
                    leftSiblingNode->keys.push_back(rootKey);
                    logger.log("internal node size "+to_string(leftSiblingNode->keys.size()));
                    InternalNode*internalNode=(InternalNode*)node;
                    
                    leftSiblingNode->keys.insert(leftSiblingNode->keys.end(),internalNode->keys.begin(),internalNode->keys.end());
                    logger.log("internal node size "+to_string(internalNode->keys.size()));
                    leftSiblingNode->tree_pointers.insert(leftSiblingNode->tree_pointers.end(),internalNode->tree_pointers.begin(),internalNode->tree_pointers.end());
                    leftSiblingNode->size+=internalNode->size;
                    this->keys.erase(this->keys.begin()+(index-1));
                    this->tree_pointers.erase(this->tree_pointers.begin()+(index));
                    this->size--;
                    this->dump();
                    leftSiblingNode->dump();
                    logger.log("left sibling node dumped");
                    delete internalNode;
                    logger.log("internal node deleted");
                }
            }
            else
            {
                logger.log("in the right sibling node");
                TreePtr rightSibling=this->tree_pointers[index+1];
                InternalNode* rightSiblingNode=(InternalNode*)TreeNode::tree_node_factory(rightSibling);
                if(rightSiblingNode->size>MIN_OCCUPANCY)
                {
                    logger.log("right sibling node is greater than occupancy");
                    Key rootKey=this->keys[index];
                    Key key=rightSiblingNode->keys.front();
                    InternalNode*internalNode=(InternalNode*)node;
                    TreePtr treePtr=rightSiblingNode->tree_pointers.front();
                    rightSiblingNode->keys.erase(rightSiblingNode->keys.begin());
                    rightSiblingNode->tree_pointers.erase(rightSiblingNode->tree_pointers.begin());
                    rightSiblingNode->size--;
                    internalNode->keys.insert(internalNode->keys.end(),rootKey);
                    internalNode->tree_pointers.insert(internalNode->tree_pointers.end(),treePtr);
                    internalNode->size++;
                    this->keys[index]=key;
                    this->dump();
                    rightSiblingNode->dump();
                    internalNode->dump();
                }
                else
                {
                    logger.log("right sibling node is min occ");
                    Key rootKey=this->keys[index];
                    logger.log("root key "+to_string(rootKey));
                    InternalNode*internalNode=(InternalNode*)node;
                    logger.log("internal node size "+to_string(internalNode->keys.size()));
                    // internalNode->keys[internalNode->keys.size()-1]=rootKey;
                    internalNode->keys.push_back(rootKey);
                    logger.log("internal node size "+to_string(internalNode->keys.size()));
                    internalNode->keys.insert(internalNode->keys.end(),rightSiblingNode->keys.begin(),rightSiblingNode->keys.end());
                    logger.log("internal node size "+to_string(internalNode->keys.size()));
                    internalNode->tree_pointers.insert(internalNode->tree_pointers.end(),rightSiblingNode->tree_pointers.begin(),rightSiblingNode->tree_pointers.end());
                    internalNode->size=internalNode->size+rightSiblingNode->size;
                    this->keys.erase(this->keys.begin()+index);
                    this->tree_pointers.erase(this->tree_pointers.begin()+(index+1));
                    this->size--;
                    this->dump();
                    internalNode->dump();
                    // rightSiblingNode->dump();
                    delete rightSiblingNode;
                }
            }
        }
    }
    logger.log("before curr node dumping");
    // logger.log("in the internalNode to delete a key");
    this->dump();
    logger.log("curr node dumped");
}

//runs range query on subtree rooted at this node
void InternalNode::range(ostream &os, const Key &min_key, const Key &max_key) const {
    BLOCK_ACCESSES++;
    for (int i = 0; i < this->size - 1; i++) {
        if (min_key <= this->keys[i]) {
            auto* child_node = TreeNode::tree_node_factory(this->tree_pointers[i]);
            child_node->range(os, min_key, max_key);
            delete child_node;
            return;
        }
    }
    auto* child_node = TreeNode::tree_node_factory(this->tree_pointers[this->size - 1]);
    child_node->range(os, min_key, max_key);
    delete child_node;
}

//exports node - used for grading
void InternalNode::export_node(ostream &os) {
    TreeNode::export_node(os);
    for (int i = 0; i < this->size - 1; i++)
        os << this->keys[i] << " ";
    os << endl;
    for (int i = 0; i < this->size; i++) {
        auto child_node = TreeNode::tree_node_factory(this->tree_pointers[i]);
        child_node->export_node(os);
        delete child_node;
    }
}

//writes subtree rooted at this node as a mermaid chart
void InternalNode::chart(ostream &os) {
    string chart_node = this->tree_ptr + "[" + this->tree_ptr + BREAK;
    chart_node += "size: " + to_string(this->size) + BREAK;
    chart_node += "]";
    os << chart_node << endl;

    for (int i = 0; i < this->size; i++) {
        auto tree_node = TreeNode::tree_node_factory(this->tree_pointers[i]);
        tree_node->chart(os);
        delete tree_node;
        string link = this->tree_ptr + "-->|";

        if (i == 0)
            link += "x <= " + to_string(this->keys[i]);
        else if (i == this->size - 1) {
            link += to_string(this->keys[i - 1]) + " < x";
        } else {
            link += to_string(this->keys[i - 1]) + " < x <= " + to_string(this->keys[i]);
        }
        link += "|" + this->tree_pointers[i];
        os << link << endl;
    }
}

ostream& InternalNode::write(ostream &os) const {
    TreeNode::write(os);
    for (int i = 0; i < this->size - 1; i++) {
        if (&os == &cout)
            os << "\nP" << i + 1 << ": ";
        os << this->tree_pointers[i] << " ";
        if (&os == &cout)
            os << "\nK" << i + 1 << ": ";
        os << this->keys[i] << " ";
    }
    if (&os == &cout)
        os << "\nP" << this->size << ": ";
    os << this->tree_pointers[this->size - 1];
    return os;
}

istream& InternalNode::read(istream& is) {
    TreeNode::read(is);
    this->keys.assign(this->size - 1, DELETE_MARKER);
    this->tree_pointers.assign(this->size, NULL_PTR);
    for (int i = 0; i < this->size - 1; i++) {
        if (&is == &cin)
            cout << "P" << i + 1 << ": ";
        is >> this->tree_pointers[i];
        if (&is == &cin)
            cout << "K" << i + 1 << ": ";
        is >> this->keys[i];
    }
    if (&is == &cin)
        cout << "P" << this->size;
    is >> this->tree_pointers[this->size - 1];
    return is;
}
