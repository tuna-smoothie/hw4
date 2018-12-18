CXXFLAGS = -Wall

all: airport distance testCode testFacility testRunway testSiteNumber

airport: airport.o Facility.o Runway.o
	$(CXX) -o $@ $^

distance: distance.o Facility.o
	$(CXX) -o $@ $^
	
testCode: testCode.o Facility.o	
	$(CXX) -o $@ $^
	
testFacility: testFacility.o Facility.o	
	$(CXX) -o $@ $^

testRunway: testRunway.o Runway.o	
	$(CXX) -o $@ $^

testSiteNumber: testSiteNumber.o Runway.o Facility.o
	$(CXX) -o $@ $^

clean:
	rm -f airport distance testCode testFacility testRunway testSiteNumber *.o