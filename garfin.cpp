#include <iostream>
#include <string>

using namespace std;

const int MAX_POSTS = 5;
const int MAX_COMMENTS = 5;
const int MAX_SUBCOMMENTS = 5;

string posts[MAX_POSTS];                    // Array to store posts
string comments[MAX_POSTS][MAX_COMMENTS];   // 2D array for comments
string subcomments[MAX_POSTS][MAX_COMMENTS][MAX_SUBCOMMENTS]; // 3D array for subcomments

int post_count = 0;     // Track number of posts
int comment_count[MAX_POSTS] = {0};     // Track number of comments per post
int subcomment_count[MAX_POSTS][MAX_COMMENTS] = {0};  // Track number of subcomments per comment


// Function declarations
void showMenu();
void createPost();
void addComment();
void addSubcomment();
void viewSpecificPost();
void viewAllPosts();
void displayPostWithComments(int postID);

int main() {
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
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
            viewAllPosts();
            break;
        case 6:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}



// Function to display the main menu
void showMenu() {
    cout << '\n';
     cout << '\n';
    cout << "\n   EPBI.COM\n";
    cout << "1. What's On your Mind? \n";
    cout << "2. Comment \n";
    cout << "3. Reply to a Comment \n";
    cout << "4. View Specific Post\n";
    cout << "5. View All Posts\n";
    cout << "6. Exit\n";
    cout << "Enter your choice: ";
     cout << '\n';
}



// Function to create a new post
void createPost() {
    if (post_count >= MAX_POSTS) {
        cout << "Cannot add more posts. Limit reached.\n";
        return;
    }

    cout << "Enter your post: ";
    cin.ignore();
    getline(cin, posts[post_count]);
    cout << "Post added successfully! Post ID is " << post_count << ".\n";
    post_count++;
}



// Function to add a comment to a specific post
void addComment() {
    int postID;

    if (post_count == 0) {
        cout << "No posts available. Please create a post first.\n";
        return;
    }

    viewAllPosts();
    cout << "Enter the Post ID to comment on: ";
    cin >> postID;

    if (postID >= post_count || postID < 0) {
        cout << "Invalid Post ID.\n";
        return;
    }

    if (comment_count[postID] >= MAX_COMMENTS) {
        cout << "Cannot add more comments. Limit reached.\n";
        return;
    }

    cout << "Enter your comment: ";
    cin.ignore();
    getline(cin, comments[postID][comment_count[postID]]);
    cout << "Comment added successfully!\n";
    comment_count[postID]++;
}



// Function to add a subcomment to a specific comment
void addSubcomment() {
    int postID, commentID;

    if (post_count == 0) {
        cout << "No posts available. Please create a post first.\n";
        return;
    }

    viewAllPosts();
    cout << "Enter the Post ID to add a subcomment: ";
    cin >> postID;

    if (postID >= post_count || postID < 0) {
        cout << "Invalid Post ID.\n";
        return;
    }

    if (comment_count[postID] == 0) {
        cout << "No comments available for this post. Add a comment first.\n";
        return;
    }

    displayPostWithComments(postID);
    cout << "Enter the Comment ID to add a subcomment: ";
    cin >> commentID;

    if (commentID >= comment_count[postID] || commentID < 0) {
        cout << "Invalid Comment ID.\n";
        return;
    }

    if (subcomment_count[postID][commentID] >= MAX_SUBCOMMENTS) {
        cout << "Cannot add more subcomments. Limit reached.\n";
        return;
    }

    cout << "Enter your subcomment: ";
    cin.ignore();
    getline(cin, subcomments[postID][commentID][subcomment_count[postID][commentID]]);
    cout << "Subcomment added successfully!\n";
    subcomment_count[postID][commentID]++;
}



// Function to display all posts and comments
void viewAllPosts() {
    if (post_count == 0) {
        cout << "No posts available.\n";
        return;
    }

    for (int i = 0; i < post_count; i++) {
        displayPostWithComments(i);
    }
}



//function to view a specific post by ID
void viewSpecificPost(){
if (post_count == 0){

    cout << "No Post available for this ID" << '\n';
    return;
}

int postID;
cout << "Enter Post ID: \n";
cin >> postID;

if (postID >= post_count || postID < 0){

    cout << "Invalid post ID \n";
    return;
}

displayPostWithComments(postID);

}



// Function to display a single post with its comments and subcomments
void displayPostWithComments(int postID) {
    cout << "\nPost ID " << postID << ": " << posts[postID] << "\n";

    if (comment_count[postID] == 0) {
        cout << "  No comments yet.\n";
    } else {
        for (int j = 0; j < comment_count[postID]; j++) {
            cout << "  Comment " << j << ": " << comments[postID][j] << "\n";

            if (subcomment_count[postID][j] == 0) {
                cout << "    No subcomments.\n";
            } else {
                for (int k = 0; k < subcomment_count[postID][j]; k++) {
                    cout << "    Subcomment " << k << ": " << subcomments[postID][j][k] << "\n";
                }
            }
        }
    }
}
