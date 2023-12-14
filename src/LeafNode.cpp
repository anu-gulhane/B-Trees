#include "RecordPtr.hpp"
#include "LeafNode.hpp"
#include "Logger.hpp"

LeafNode::LeafNode(const TreePtr &tree_ptr) : TreeNode(LEAF, tree_ptr) {
    this->data_pointers.clear();
    this->next_leaf_ptr = NULL_PTR;
    if(!is_null(tree_ptr))
        this->load();
}

//returns max key within this leaf
Key LeafNode::max() {
    auto it = this->data_pointers.rbegin();
    return it->first;
}

//inserts <key, record_ptr> to leaf. If overflow occurs, leaf is split
//split node is returned
//TODO: LeafNode::insert_key to be implemented
TreePtr LeafNode::insert_key(const Key &key, const RecordPtr &record_ptr) {
    logger.log("insert key function in leaf node");
    TreePtr new_leaf = NULL_PTR; //if leaf is split, new_leaf = ptr to new split node ptr
    // cout << "LeafNode::insert_key not implemented" << endl;
    
    if(this->is_full())
    {
        logger.log("leaf node is full");
        this->data_pointers[key]=record_ptr;
        this->size++;
        int splitIndex=ceil((float)this->size/2);
        // logger.log("split index "+to_string(splitIndex));
        LeafNode*newNode=new LeafNode();
        int i=0;
        for(auto it = this->data_pointers.begin(); it != this->data_pointers.end(); )
        {
            // logger.log("sfda");
            auto elem=*it;
            logger.log(to_string(elem.first));
            if(i<splitIndex)
            {
                i++;
                it++;
                // continue;
            }
            else
            {
                logger.log("inserting key into new node " + to_string(elem.first));
                Key key=elem.first;
                RecordPtr record_ptr=elem.second;
                newNode->data_pointers[key]=record_ptr;
                newNode->size+=1;
                it=this->data_pointers.erase(it);
                logger.log("erasing data pointer");
                i++;
                // it++;

            }
            
            // logger.log("helo");
        }
        logger.log("out of the loop");
        newNode->next_leaf_ptr=this->next_leaf_ptr;
        this->next_leaf_ptr=newNode->tree_ptr;
        this->size=splitIndex;
        logger.log("old node size "+to_string(this->size));
        logger.log("new node size "+to_string(newNode->size));
        newNode->dump();

        new_leaf=newNode->tree_ptr;
        
        delete newNode;
    }
    else
    {
        logger.log("leaf node is not full");
        this->data_pointers[key]=record_ptr;
        this->size++;
    }
    logger.log("before dump");
    this->dump();
    logger.log("key added successfully");
    logger.log("pointer to return "+new_leaf);
    return new_leaf;
}

//key is deleted from leaf if exists
//TODO: LeafNode::delete_key to be implemented
void LeafNode::delete_key(const Key &key) {
    logger.log("in the leaf node to delete a key");
    // cout << "LeafNode::delete_key not implemented" << endl;
    if(this->data_pointers.find(key)!=this->data_pointers.end())
    {
        this->data_pointers.erase(key);
        this->size--;
        logger.log("node deleted ");
    }
    this->dump();
}

//runs range query on leaf
void LeafNode::range(ostream &os, const Key &min_key, const Key &max_key) const {
    BLOCK_ACCESSES++;
    for(const auto& data_pointer : this->data_pointers){
        if(data_pointer.first >= min_key && data_pointer.first <= max_key)
            data_pointer.second.write_data(os);
        if(data_pointer.first > max_key)
            return;
    }
    if(!is_null(this->next_leaf_ptr)){
        auto next_leaf_node = new LeafNode(this->next_leaf_ptr);
        next_leaf_node->range(os, min_key, max_key);
        delete next_leaf_node;
    }
}

//exports node - used for grading
void LeafNode::export_node(ostream &os) {
    TreeNode::export_node(os);
    for(const auto& data_pointer : this->data_pointers){
        os << data_pointer.first << " ";
    }
    os << endl;
}

//writes leaf as a mermaid chart
void LeafNode::chart(ostream &os) {
    string chart_node = this->tree_ptr + "[" + this->tree_ptr + BREAK;
    chart_node += "size: " + to_string(this->size) + BREAK;
    for(const auto& data_pointer: this->data_pointers) {
        chart_node += to_string(data_pointer.first) + " ";
    }
    chart_node += "]";
    os << chart_node << endl;
}

ostream& LeafNode::write(ostream &os) const {
    TreeNode::write(os);
    for(const auto & data_pointer : this->data_pointers){
        if(&os == &cout)
            os << "\n" << data_pointer.first << ": ";
        else
            os << "\n" << data_pointer.first << " ";
        os << data_pointer.second;
    }
    os << endl;
    os << this->next_leaf_ptr << endl;
    return os;
}

istream& LeafNode::read(istream& is){
    TreeNode::read(is);
    this->data_pointers.clear();
    for(int i = 0; i < this->size; i++){
        Key key = DELETE_MARKER;
        RecordPtr record_ptr;
        if(&is == &cin)
            cout << "K: ";
        is >> key;
        if(&is == &cin)
            cout << "P: ";
        is >> record_ptr;
        this->data_pointers.insert(pair<Key,RecordPtr>(key, record_ptr));
    }
    is >> this->next_leaf_ptr;
    return is;
}