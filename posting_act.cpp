#include <iostream>
#include <string>

using namespace std;

  const int maxPost = 10;
  const int maxComment = 10;
  const int maxSubcomment = 10;

    string post[maxPost];                                   // storing post in array
    string comments[maxPost][maxComment];                   // storing comment in 2d array
    string subcomments[maxPost][maxComment][maxSubcomment]; // storing subcomment in 3d array

      int postCount = 0;                               // tracking number of post
      int commentCount[maxPost] = {0};                 // tracking comments per post
      int subComment_count[maxPost][maxComment] = {0}; // tracking sub comments per comment

        // function declarations
        void myMenu();
        void createPost();
        void addComment();
        void addSubcomment();
        void viewSpecificPost();
        void viewNewsfeed();
        void displayPost(int postID); // function for viewing post with all of its comment and subcomment

    int main()
    {

      int choice;

      do
      {
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
          viewSpecificPost();
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

      } while (choice != 6);

      return 0;
    }



//MENU PANEL
  void myMenu()
  {

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
    void createPost()
    {

      if (postCount >= maxPost)
      {
        cout << "ERROR: Limit post reached! \n";
        return;
      }

      cout << "Whats on Your Mind?: \n";
      cin.ignore();
      getline(cin, post[postCount]);
      cout << "Post Added! your Post ID is: " << postCount << '\n'; // the ID is per post count
      postCount++;
    }

    // adding comments
    void addComment()
    {
      int postID;

        if (postCount == 0)
        {
          cout << "ERROR: Create a post first! \n";
          return;
        }

      viewNewsfeed();
      cout << "ENTER POST ID: ";
      cin >> postID;

          if (postID >= postCount || postID < 0)
          {
            cout << "ERROR: Invalid Post ID. Make sure that you entered a VALID ID! \n";
            return;
          }

            if (commentCount[postID] >= maxComment)
            {
              cout << "ERROR: Can't add comments. LIMIT REACHED! \n";
              return;
            }

      cout << "Enter your comment: ";
      cin.ignore();
      getline(cin, comments[postID][commentCount[postID]]);
      cout << "Comment added Succesfully! ";

      commentCount[postID]++;


    // Display the updated post with the new comment that the user added
      displayPost(postID);
    }


// adding subComments
void addSubcomment()
{
  int postID, commentID;

  if (postCount == 0)
  {
    cout << "ERROR: No post available. \n";
    return;
  }

  viewNewsfeed();

  cout << "Enter POST ID to add a reply.\n";
  cin >> postID;

//check if the ID inputted by the user is existing
  if (postID >= postCount || postID < 0)
  {
    cout << " ERROR: Invalid Post ID. Make sure that you entered a VALID ID.\n";
    return;
  }

  //check if the post has a comment, if none, message will display
  if (commentCount[postID] == 0)
  {
    cout << "No comments availble for this post. Add a comment first\n";
    return;
  }

  displayPost(postID);
  cout << "Enter COMMENT ID to add a reply.\n";
  cin >> commentID;

  if (commentID >= commentCount[postID] || commentID < 0)
  {
    cout << "ERROR: Invalid post ID. \n";
    return;
  }

  if (subComment_count[postID][commentID] >= maxSubcomment)
  {
    cout << "Can't add more replies. Limit reached!\n";
    return;
  }

  cout << "Enter your reply: ";
  cin.ignore();
  getline(cin, subcomments[postID][commentID][subComment_count[postID][commentID]]);
  cout << "Your reply is added sucesfully!\n";

  subComment_count[postID][commentID]++;

//display the updated post with the new subcomment-comment
  displayPost(postID);
}


// view a specific post based on ID that the user INPUTS
void viewSpecificPost()
{
  // check idn the ID has a post
  if (postCount == 0)
  {
    cout << "ERROR: No post for this ID." << '\n';
    return;
  }

  int postID;
  cout << "Enter the Post ID: ";
  cin >> postID;

// displays if the ID is not existing
  if (postID >= postCount || postID < 0)
  {
    cout << "ERROR: INVALID POST ID! \n";
    return;
  }

  displayPost(postID);
}


// view all the posts (10 post max)
void viewNewsfeed()
{
  if (postCount == 0)
  {
    cout << "ERROR: No post Available.\n";
    return;
  }

  for (int i = 0; i < postCount; i++)
  {
    displayPost(i);
  }
}



// displaying a post with its components (comments and subcomments)
void displayPost(int postID)
{
  if (postID < 0 || postID >= postCount)
  {
    cout << "ERROR: Invalid Post ID.\n";
    return;
  }

  if (post[postID].empty())
  {
    cout << "ERROR: This post is empty.\n";
    return;
  }

  cout << "\n Post ID: " << postID << "; " << post[postID] << "\n";

  if (commentCount[postID] == 0)
  {
    cout << "This post has no comments yet.\n";
  }
  else
  {
    for (int j = 0; j < commentCount[postID]; j++)
    {
        // for comments
      cout << " Comment " << j << ": " << comments[postID][j] << '\n';

        // reply to a comment
      if (subComment_count[postID][j] == 0)
      {
        cout << "No Replies.\n";
      }

      else
      {
        // reply to a comment or a subcomment
        for (int k = 0; k < subComment_count[postID][j]; k++)
        {
          cout << "   Replies " << k << ": " << subcomments[postID][j][k] << "\n";
        }
      }
    }
  }
}
