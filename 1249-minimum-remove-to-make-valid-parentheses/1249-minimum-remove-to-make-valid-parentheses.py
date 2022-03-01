class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        
        #keep track of left and right parantheses
        
        bal = 0
        indices_to_remove = set()
        #first pass do not add invalid closing parantheses
        for index, char in enumerate(s):
            
            #count left and right 
            if char == "(":
                bal = bal + 1
            if char == ")":
                if bal <= 0:
                    indices_to_remove.add(index)
                else:
                    bal = bal - 1
            
                
        # we have extra open parantheses
        index = len(s) - 1
        while bal > 0:
            #iterate from reverse and remove open parantheses
            if s[index] == "(":
                indices_to_remove.add(index)
                bal = bal - 1
            index = index - 1
            
        #build output 
        output = ""
        for index, char in enumerate(s):
            if index not in indices_to_remove:
                output = output + char
        return output            
                
            
            
                
                
                
        
        return output
                
        