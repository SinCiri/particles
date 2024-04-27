#include "Engine.h"

Engine::Engine() {
	VideoMode vm(VideoMode::getDesktopMode().width, VideoMode::getDesktopMode().height);
	m_Window.create(vm, "Particles.exe", Style::Default);
}
void Engine::run() {
	Clock clock;
	//unit test for particles.
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2, (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete.  Starting engine..." << endl;
	//game loop
	while (m_Window.isOpen()) {
		//restart the clock since last frame
		clock.restart();
		//get the time of the clock
		Time GameTime = clock.getElapsedTime();
		//keep track of the total time elapced.
		float timeElapced = timeElapced + GameTime.asSeconds();
		input();
		update(timeElapced);
		draw();
	}
}

void Engine::input() {
	Event event;
	m_Window.pollEvent(event);
	if (Keyboard::isKeyPressed(Keyboard::Escape)) {
		m_Window.close();
	}
	if (event.type == Event::MouseButtonPressed) {
		if (event.mouseButton.button == Mouse::Left) {
		cout << "Click" << endl;
		}
	}
}

void Engine::update(float dtAsSeconds) {

}

void Engine::draw() {
	m_Window.clear();
	for (auto i : m_particles) {
		m_window.draw(i);
	}
	m_window.display();

}


