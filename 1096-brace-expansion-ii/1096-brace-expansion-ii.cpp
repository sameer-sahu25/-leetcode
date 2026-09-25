class Solution {
public:
    int i = 0;

    
    set<string> multiply(set<string>& A, set<string>& B) {
        set<string> res;

        for (auto &a : A) {
            for (auto &b : B) {
                res.insert(a + b);
            }
        }

        return res;
    }

    set<string> parseExpr(string& s) {
        set<string> res = parseTerm(s);

        while (i < s.size() && s[i] == ',') {
            i++;
            set<string> nxt = parseTerm(s);

            res.insert(nxt.begin(), nxt.end());
        }

        return res;
    }

    
    set<string> parseTerm(string& s) {
        set<string> res;
        res.insert("");

        while (i < s.size() && s[i] != '}' && s[i] != ',') {
            set<string> factor = parseFactor(s);
            res = multiply(res, factor);
        }

        return res;
    }

    
    set<string> parseFactor(string& s) {
        if (islower(s[i])) {
            return {string(1, s[i++])};
        }

        i++; 
        set<string> res = parseExpr(s);
        i++;

        return res;
    }

    vector<string> braceExpansionII(string expression) {
        i = 0;
        set<string> ans = parseExpr(expression);

        return vector<string>(ans.begin(), ans.end());
    }
};