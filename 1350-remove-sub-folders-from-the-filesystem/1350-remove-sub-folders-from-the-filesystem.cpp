class Solution {
public:
vector<string> removeSubfolders(vector<string>& folder) {
    // Sort the folders lexicographically so that sub-folders come immediately after their parent folder
    sort(folder.begin(), folder.end());
    
    // Result vector to store folders without sub-folders
    vector<string> result;
    
    // Initialize previous folder to an empty string
    string prevFolder = "";

    // Traverse each folder in the sorted list
    for (const string& f : folder) {
        // Check if the current folder is not a sub-folder of the previous one
        // The condition checks if f starts with prevFolder and is not exactly equal to prevFolder
        // The `prevFolder.size()` is used to ensure it's a sub-folder structure like "/a/b"
        if (prevFolder.empty() || f.substr(0, prevFolder.size()) != prevFolder || f[prevFolder.size()] != '/') {
            // If it's not a sub-folder, add it to the result
            result.push_back(f);
            // Update prevFolder to the current folder
            prevFolder = f;
        }
    }
    
    return result;
}
};