#include <iostream>
#include <string>

using namespace std;

const int maxPost = 10;
const int maxComment = 10;
const int maxSubcomment = 10;

string post[maxPost]; //storing post in array
string comments [maxPost][maxComment]; // storing comment in 2d array
string subcomments[maxPost] [maxComment] [maxSubcomment]; // storing subcomment in 3d array

int postCount = 0; //tracking number of post 
int commentCount[maxPost] = {0}; //tracking comments per post
int subComment_count[maxPost][maxComment] = {0}; //tracking sub comments per comment 

// function declarations

void myMenu();
void createPost();
void addComment();
void addSubcomment();
void viewPost();
void viewNewsfeed();
void displayPost(int postID); //function for viewing post with all of its comment and subcomment

int main (){

  int choice;

  do{
    myMenu();
    cin >> choice;

    switch (choice)
    {
    case 1:
      createPost();
      break;

      case 2:
        addComment();
        break;

        case 3:
          addSubcomment();
          break;

            case 4:
              viewPost();
            break;

              case 5:
                viewNewsfeed();
                break;

                  case 6:
                    cout << "EXITING PROGRAM \n";
                    break;
      default:
      cout << "ERROR: Invalid Choice! \n ";        
    }

  } while (choice != 5);
   
  return 0;
}


void myMenu (){
  
  cout << "\n";
  cout << "\n";
      cout << "EPBI DAT COM\n";
  cout << "\n";
  cout << "\n";

      cout << "1. What's on your Mind? \n";  
      cout << "2. Comment \n";
      cout << "3. Reply to a Comment \n";
      cout << "4. View Post \n";
      cout << "5. View All Post \n";
      cout << "6. EXIT \n";

  cout << "\n";
  cout << "Enter your choice:";
 

}


// function for creating a post
void createPost(){

  if (postCount >= maxPost){
    cout << "ERROR: Limit post reached! \n";
    return;
  }

    cout << "Whats on Your Mind?: \n";
      cin.ignore();
      cin >> post[postCount];
    cout << "Post Added! your Post ID is: " << postCount << '\n'; // the ID is per post count 
      postCount++;
}


// adding comments
void addComment (){
  int postID;

  if (postCount == 0){
    cout << "ERROR: Create a post first! \n";
    return;
  }

  
  viewNewsfeed();
  cout << "ENTER POST ID: ";
  cin >> postID;

  if(postID >= postCount || postID < 0){
    cout << "ERROR: Invalid Post ID. Make sure that you entered a VALID ID! \n";
    return;
  }

  if (commentCount[postID] >= maxComment )
    cout << "ERROR: Can't add comments. LIMIT REACHED! \n";
  return;

  cout << "Enter your comment: ";
  cin.ignore();
  cin >> comments[postID][commentCount[postID]];

  commentCount[postID]++;
}




// adding subComments
void addSubcomment(){




  
}


// view a specific post based on ID that the user INPUTS
void viewPost(){
  cout << "nigga";
}


// view all the posts (10 post max)
void viewNewsfeed(){
cout << "nigga";
}


// displaying a post with its components (comments and subcomments)
void displayPost(int postID){
  cout << "nigga";
}