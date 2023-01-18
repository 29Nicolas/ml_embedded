#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <ctime>
#include "tensorflow/lite/interpreter.h"
#include "tensorflow/lite/kernels/register.h"
#include "tensorflow/lite/model.h"
#include "tensorflow/lite/tools/gen_op_registration.h"
#include "test_dataset.h"

int main(){
	int match=0;

	int class_predicted;

	float max_score=0;

	auto model=tflite::FlatBufferModel::BuildFromFile("model.tflite");

	tflite::ops::builtin::BuiltinOpResolver resolver;
	std::unique_ptr<tflite::Interpreter> interpreter;
	tflite::InterpreterBuilder(*model, resolver)(&interpreter);

	interpreter->AllocateTensors();

	float *input=interpreter->typed_input_tensor<float>(0);
	
	clock_t begin=clock();

	for (int i=0; i<N_TEST_EXAMPLES; i++){

		for (int j=0; j<N_FEATURES; j++){
			input[j]=X_test[i][j];
		}
		
		interpreter->Invoke();

		float *output=interpreter->typed_output_tensor<float>(0);
		
		max_score=output[0];
		class_predicted=0;
		for (int j=1; j<N_CLASSES; j++){
			if (output[j] > max_score) {
				max_score=output[j];
				class_predicted=j;
			}
		}
		if (class_predicted == y_test[i]){
			match++;
		}
	}
	
	clock_t end=clock();
	std::cout << "Match: " << match << std::endl;
	std::cout << "Accuracy on training platform: " << test_acc << " %\n";
	std::cout << "Accuracy on inference platform: " << float(match)/float(N_TEST_EXAMPLES) << " %\n";
	std::cout << "Prediction time: " << double(end-begin)/CLOCKS_PER_SEC << "s\n";

	return 1;
}
