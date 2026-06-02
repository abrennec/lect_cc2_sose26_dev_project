# Part 1 Object Orientated Programming 
>Bonita von Gizycki

*OOP macht Code wartbar, wiederverwendbar und organisiert.*

## 1. What is the main idea of object-oriented programming?

 Statt Code in einer großen `draw()`-Funktion zu haben, packt man zusammenhängende Dinge in "Objekte" (= Klassen). Z.B. eine `Snake`-Klasse mit all dem Snake-Zeug drin statt überall `drawSnake()`, `updateSnake()`, etc. aufzurufen.


## 2. How do you create a class as well as an object in C++?

```jsx
// 1. KLASSE definieren (in ofSnake.h)
class ofSnake {
  public:
    void draw();
  private:
    int speed;
};

// 2. OBJEKT erstellen (in ofApp.h)
class ofApp {
  ofSnake mySnake;  // ← Das ist das Objekt!
};

// 3. OBJEKT nutzen (in ofApp.cpp)
void ofApp::draw() {
  mySnake.draw();   // ← Objekt-Methode aufrufen
}
```

noch simpler:

```jsx
// Schritt 1: Die KLASSE (= die Vorlage)
class Effekt {
  public:
    void draw() { /* zeichne mich */ }
};

// Schritt 2: Ein OBJEKT (= das echte Ding)
Effekt myEffekt;  // ← Das ist das Objekt!

// Schritt 3: Das Objekt nutzen
myEffekt.draw();
```

## 3. What are classes, objects, and instances and how are they related?

• **Klasse** = das Rezept/die Vorlage (z.B. "ofSnake") – **Bauplan**

• **Objekt/Instance** = das fertige Ding (z.B. "mySnake") – das fertige Haus

• Relation: Objekt ist eine **Instanz** der Klasse. So wie `int x` eine Instanz vom Typ `int` ist – ein konkretes Haus (= Objekt)


→ Beispiel: `Effekt` ist die Klasse. `myEffekt` ist die Instance/das Objekt.

## 4. What syntax is needed to create a class?

```jsx
class ClassName {
  public:
    void publicMethod();    // von außen sichtbar
    ClassName();            // Konstruktor (setup)
    ~ClassName();           // Destruktor (cleanup)
    
  private:
    int privateVariable;    // nur intern sichtbar
};
```

noch simpler:

```jsx
class Effekt {
  public:
    void draw();
    
  private:
    int speed;
};
```

## 5. What are access levels (meant for)?

• **public** = jeder kann zugreifen (`mySnake.draw()`)

• **private** = nur die Klasse selbst kann zugreifen (Schutzmechanismus)

• **protected** = nur geerbte Klassen können zugreifen (später relevant)

**Zweck:** Deine Daten schützen! Der User soll nur das benutzen, was er benutzen darf.
 
```jsx
 class Effekt {
   public:
     void draw();  // ← Jeder kann das aufrufen!
     
   private:
     int speed;    // ← Nur Effekt selbst kann das ändern!
 };
 
 // In ofApp:
 myEffekt.draw();      // ✅ Geht!
 myEffekt.speed = 10;  // ❌ Geht nicht! (private)
```
>