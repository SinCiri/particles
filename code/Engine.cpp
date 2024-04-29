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
		float timeElapced = GameTime.asSeconds();
		timeElapced = timeElapced + GameTime.asSeconds();
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
		for (int i = 0; i < 5; i++) {
			Particle p(m_Window, rand() % 30 + 25, Mouse::getPosition());
			m_particles.push_back(p);
		}
		}
	}
}


//definitaly check this function more, seems to work but something is off about the iterator usage
void Engine::update(float dtAsSeconds) {
	vector<Particle>::iterator iter;
	int i = 0;
	for (iter = m_particles.begin(); iter < m_particles.end();) {
		if (m_particles.at(i).getTTL() > 0.0) {
			m_particles.at(i).update(dtAsSeconds);
			iter++;
			i++;
		}
		else {
			iter = m_particles.erase(iter);
		}
	}

}

void Engine::draw() {
	m_Window.clear();
	for (auto i : m_particles) {
		m_Window.draw(i);
	}
	m_Window.display();

}


