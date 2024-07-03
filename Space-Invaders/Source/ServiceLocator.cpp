#include <iostream>
using namespace std;
#include"../HeaderFiles/ServiceLocator.h"

// Initialize the static instance pointer
ServiceLocator* ServiceLocator::instance = nullptr;

ServiceLocator::ServiceLocator(){
	graphic_service = nullptr;
	createServices();
}
ServiceLocator::~ServiceLocator() {

	clearAllServices();
}
// Get the single instance of ServiceLocator
ServiceLocator* ServiceLocator::getInstance() {
	static ServiceLocator instance;
		return &instance;
}
void ServiceLocator::initialize(){
	//initializes the service locator class
	graphic_service->initialize();
}
void ServiceLocator::update() {
	//Keeps on updating services required and updates the game state
	graphic_service->update();
}
void ServiceLocator::render() {
	//Keeps on rendering the new services
	graphic_service->render();
}
void ServiceLocator::createServices() {
	graphic_service = new GraphicService();

}
void ServiceLocator::clearAllServices() {
	delete(graphic_service); // Delete the graphic_service instance
	graphic_service = nullptr; // Reset pointer to null to avoid dangling pointer
}

// Returns a pointer to the currently set graphic service.
GraphicService* ServiceLocator::GetGraphicService() { return graphic_service; }

 //ServiceLocator:: static ServiceLocator* getInstance() {

//}
