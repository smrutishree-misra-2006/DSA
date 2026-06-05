class Solution {
public:

    /* Function to determine the state of 
    asteroids after all collisions */
    vector<int> asteroidCollision(vector<int> &asteroids){
        
        // Size of the array
        int n = asteroids.size();
        
        // List implementation of stack
        vector<int> st;  
        
        // Traverse all the asteroids
        for(int i=0; i < n; i++) {
            
            /* Push the asteroid in stack if a 
            right moving asteroid is seen */
            if(asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            }
            
            /* Else if the asteroid is moving 
            right, perform the collisions */
            else {
                
                /* Until the right moving asteroids are 
                smaller in size, keep on destroying them */ 
                while(!st.empty() && st.back() > 0 && 
                      st.back() < abs(asteroids[i])) {
                    
                    // Destroy the asteroid
                    st.pop_back();
                }
                
                /* If there is right moving asteroid 
                which is of same size */
                if(!st.empty() && 
                    st.back() == abs(asteroids[i])) {
                    
                    // Destroy both the asteroids
                    st.pop_back();
                }
                
                /* Otherwise, if there is no left
                moving asteroid, the right moving 
                asteroid will not be destroyed */
                else if(st.empty() ||
                        st.back() < 0){
                    
                    // Storing the array in final state
                    st.push_back(asteroids[i]);
                }
            }
        }
        
        // Return the final state of asteroids
        return st;
    }
};