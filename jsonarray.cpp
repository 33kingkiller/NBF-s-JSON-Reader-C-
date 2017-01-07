#include "jsonarray.h"

void JsonArray::getJsonValues(int valsI[], std::string valsS[]) {
	for (int i = 0; i < 50; i++) {
		valsI[i] = valuesI[i];
		valsS[i] = valuesS[i];
	}
}

void JsonArray::getJsonObjects(JsonObject jObjects[]) {
	JsonMember tempIMembers[50];
	JsonMember tempSMembers[50];

	for (int i = 0; i < 50; i++) {
		objects[i].getIntMembers(tempIMembers);
		jObjects[i].setIntMembers(tempIMembers);

		objects[i].getStringMembers(tempSMembers);
		jObjects[i].setStringMembers(tempSMembers);
	}
}

JsonObject JsonArray::getJsonObject(int id) {
	return objects[id];
}

void JsonArray::setJsonValue(int id, std::string value) {
	valuesS[id] = value;
}

void JsonArray::setJsonValue(int id, int value) {
	valuesI[id] = value;
}

void JsonArray::setJsonObject(int id, JsonObject jObject) {
	JsonMember tempMembersI[50];
	JsonMember tempMembersS[50];
	
	jObject.getIntMembers(tempMembersI);
	jObject.getStringMembers(tempMembersS);

	objects[id].setIntMembers(tempMembersI);
	objects[id].setStringMembers(tempMembersS);
}

void JsonArray::setJsonObject(int id, JsonMember jMembers[], bool isString) {
	if (isString) {
		objects[id].setStringMembers(jMembers);
	}
	else {
		objects[id].setIntMembers(jMembers);
	}
}
