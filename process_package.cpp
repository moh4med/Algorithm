/*
 * process_package.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: Mohamed
 */
#include<bits/stdc++.h>
using namespace std;
struct Request {
	Request(int arrival_time, int process_time) :
			arrival_time(arrival_time), process_time(process_time) {
	}

	int arrival_time;
	int process_time;
};

struct Response {
	Response(bool dropped, int start_time) :
			dropped(dropped), start_time(start_time) {
	}

	bool dropped;
	int start_time;
};

class Buffer {
public:
	Buffer(int size) :
			size_(size), finish_time_() {
	}

	Response Process(const Request &request) {

		while (!finish_time_.empty()
				&& finish_time_.front() <= request.arrival_time) {
			finish_time_.pop();
		}
		if (finish_time_.empty()) {
			finish_time_.push(request.arrival_time + request.process_time);
			return (Response(false, request.arrival_time));
		}
		if (finish_time_.size() < this->size_) {
			int x=finish_time_.back();
			finish_time_.push(finish_time_.back() + request.process_time);
			return (Response(false,x));
		} else {
			return (Response(true, -1));
		}

		// write your code here
	}
private:
	int size_;
	std::queue<int> finish_time_;
};

std::vector<Request> ReadRequests() {
	std::vector<Request> requests;
	int count;
	std::cin >> count;
	for (int i = 0; i < count; ++i) {
		int arrival_time, process_time;
		std::cin >> arrival_time >> process_time;
		requests.push_back(Request(arrival_time, process_time));
	}
	return requests;
}

std::vector<Response> ProcessRequests(const std::vector<Request> &requests,
		Buffer *buffer) {
	std::vector<Response> responses;
	for (int i = 0; i < requests.size(); ++i)
		responses.push_back(buffer->Process(requests[i]));
	return responses;
}

void PrintResponses(const std::vector<Response> &responses) {
	for (int i = 0; i < responses.size(); ++i)
		std::cout << (responses[i].dropped ? -1 : responses[i].start_time)
				<< std::endl;
}



