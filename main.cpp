#include "PrototypeScene.h"

int main()
{
	std::shared_ptr<Scene> ps(new PrototypeScene);

	System.addScene(1, ps);

	System.pushScene(ps);

    System.runWindow();

    return 0;
}
