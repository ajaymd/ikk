// Using C++14 (gcc-5 5.1.1) 

#include "spoj.h"
#include <bits/stdc++.h>

using namespace std;

class ResultStruct {
public:
    bool   result;
    float  score;
    string message;
};

string read_whole_file_into_string(FILE * f) {

	char * buffer = '\0';
	int length;
	
	if (f) {
		fseek (f, 0, SEEK_END);
		length = (int) ftell (f);
		fseek (f, 0, SEEK_SET);
		buffer = (char *) malloc (length + 1);
		if (buffer) {
			fread (buffer, 1, length, f);
			buffer[length] = '\0';
		}
	}
	if (buffer) {
		return string(buffer);
	}
	return "";
}

// ------------------------- START -------------------------

void run_custom_checker(stringstream &input_file, stringstream &expected_output_file, stringstream &output_file, 
	ResultStruct &r_obj) {
    //Don't print anything to STDOUT in this function
    //Enter your custom checker scoring logic here
    
    int dag_nodes, dag_edges;
    input_file >> dag_nodes >> dag_edges;
    vector<int> dag_from(dag_edges);
    vector<int> dag_to(dag_edges);
    vector<int> dag_weight(dag_edges);
    for (int dag_i = 0; dag_i < dag_edges; dag_i++) {
        input_file >> dag_from[dag_i] >> dag_to[dag_i] >> dag_weight[dag_i];
    }
    int from_node;
    input_file >> from_node;
    input_file.ignore(numeric_limits<streamsize>::max(), '\n');
    int to_node;
    input_file >> to_node;
    input_file.ignore(numeric_limits<streamsize>::max(), '\n');
    
    
    vector<int> res;
    int res_size = 0;
    int temp;
    while (output_file >> temp)
    {
        res_size++;
        res.push_back(temp);
        
        if (res_size > dag_nodes)
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
    }
    

    if (res.size() == 0)
    {
       r_obj.result = false;
       r_obj.score = 0.0f;
       r_obj.message = "Wrong answer!";
       return;           
    }
    //cerr << res_size << endl;
    

    long long int expected_length;
    expected_output_file >> expected_length;
    
    map<pair<int, int>, int> weight;
    for (int i = 0; i < dag_edges; i++)
    {
        weight[{dag_from[i], dag_to[i]}] = dag_weight[i];
    }
    
    
    long long int length = 0;
    for (int i = 0; i < res_size - 1; i++)
    {
        if (weight.find({res[i], res[i + 1]}) == weight.end())
        {
            r_obj.result = false;
            r_obj.score = 0.0f;
            r_obj.message = "Wrong answer!";
            return;
        }
        length += weight[{res[i], res[i + 1]}];
    }
    
    //cerr << "Maximum length possible = " << expected_length << endl;
    //cerr << "Your length = " << length << endl;
    
    if (length != expected_length)
    {
       r_obj.result = false;
       r_obj.score = 0.0f;
       r_obj.message = "Wrong answer!";
       return;           
    }
    r_obj.result = true;
    r_obj.score = 1.0f;
    r_obj.message = "Success";
}
// End of BODY

// ------------------------- STOP -------------------------

int main(void) {
	spoj_init();

	string whole_input = read_whole_file_into_string(spoj_p_in);
	string whole_expected_output = read_whole_file_into_string(spoj_p_out);
	string whole_output = read_whole_file_into_string(spoj_t_out);

	cerr << "Input length: " << whole_input.length() << endl;
	// cerr << "Input:" << endl;
	// cerr << whole_input << endl;

	cerr << "Expected output length: " << whole_expected_output.length() << endl;
	// cerr << "Expected output:" << endl;
	// cerr << whole_expected_output << endl;

	cerr << "Output length: " << whole_output.length() << endl;
	// cerr << "Output:" << endl;
	// cerr << whole_output << endl;
	
    ResultStruct r_obj;
    r_obj.result = false;
    r_obj.score = 0.0f;
    r_obj.message = "Uninitialized";

    stringstream input_file(whole_input);
    stringstream expected_output_file(whole_expected_output);
    stringstream output_file(whole_output);


    run_custom_checker(input_file, expected_output_file, output_file, r_obj);
    if (r_obj.result) {
    	return SPOJ_RV_POSITIVE;
    }

	return SPOJ_RV_NEGATIVE;
}