# About Variables

Variables are introduced in **mmqlc v3.0** and will remain a standard feature of the project from now and onwards.

---

## Declaring Variables

Variables are declared using the `SET` query followed by variable name , equal sign and value that you want to assign.

**For Example:**

- `SET VAR_NAME = REAL_NUMBER`
- `SET VAR_NAME = COMPLEX_NUMBER`
- `SET VAR_NAME = QUERY ARG`
- `SET VAR_NAME = QUERY ARG_1,ARG_2`
- `SET VAR_NAME = QUERY VAR_NAME`
- `SET VAR_NAME = QUERY VAR_1,VAR_2`

are the supported modes of declaring variables.

---

## Re-Assigning Variables

Re-assigning variables is just same as how you declare variables.

---

## Getting/Fetching Variables

Variables are fetched using the `GET` query followed by variable name.

**For Example:**

- `GET VAR_NAME`

> [!WARNING]
> **It is compulsory that the variables must be declared before fetching.**

---

## Using the variables with queries

> [!NOTE]
> **The variables `a` and `b` are present somewhere in the memory of mmqlc**

### Queries that depends on two arguments

```mmql
QUERY a,b
```

### Queries that depends on one argument

```mmql
QUERY a
```

---

## Feature Underdevelopment 🐣

**Inshallah, the following features regarding variables will be completed by the next update.**

**Using variables with numbers directly**.

- `QUERY number,var`
- `QUERY var,number`

> [!NOTE]
> The type of **var** and **number** must be same. Intermixing real and complex types are not allowed.

**Assigning the value of one variable to another**:

- `SET NEW_VAR = OLD_VAR`


