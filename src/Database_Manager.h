/*
 - Makes everything lowercase
 - Removes extraneous entries
 - Should be a Singleton design pattern
 - Eventually, the database should actually be a vector of Component objects 
 
 - RE: part numbering conventions. Lower-case. Slashes will be ignored (for now).
   hyphens will be ignored (for now). underscores will not be ignored.
   Underscores for undefined configurations. They may be important to preserve.
   Investigate further.
 
 */

#ifndef Database_Manager_h
#define Database_Manager_h

#include <vector>
#include <string>


class Database_Manager
{
public:
    
    Database_Manager(); 
    
    static const std::string DATABASE_FILEPATH;
    // maybe the results of a database-read should be static const OR make whoel class singleton
    
    /*
     @brief Given a token (part number), return true for a match, else false.
            Update reference to token with matching line. 
     */
    bool search_component(std::vector<std::string>& token);
    
    
    /*
     @brief
     */
    void clean_and_sort();
    
    
    /*
     @brief
     */
    void lowercase();
    
    
    /*
     @brief
     */
    void delete_entry();
    
    
    /*
     @brief
     */
    void add_entry();
    
    
    /*
     @brief
     */
    void print_database() const;  // pass a worksheet object
    
    
    /*
     @brief
     */
    void rewrite_database() const;
    
    
private:
    
    /*
     @brief Encode the fields of the database as scoped enum, so fields aren't
     hard-coded in the class definition.
     */
    enum class Field
    {
        PART_NUMBER = 0,
        PROCUREMENT_SPEC = 1,
        PART_TYPE = 2  // follow EEE-INST-002 nomenclature 
        
    }; 
    
    std::vector<std::vector<std::string>> database;
    
};


/*
 @brief Non-member function to read and return database data. 
 */
std::vector<std::vector<std::string>> read_database();


#endif /* Database_Manager_h */
