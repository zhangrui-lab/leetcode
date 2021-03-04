<?php


/*
 * 谁是卧底？
 * N 个人，有传销和卧底。卧底多于传销数。
 * Q1: 问A，你是卧底吗？
 * Q2: 问B，A是卧底吗？
 * 卧底总真实回答问题，传销总胡说八道。
 * 如何问不多于 N-1 个问题的情况下找到一个卧底？
 *
 *
 *
 *          |  Q1(A)  |  Q2(B, A)  |  Q1(A) && Q2(B, A) |
 * -----------------------------------------------------|
 * A:t,B:t  |   t    |    t       |            t        |
 * A:t,B:f  |   t    |    t       |            t        |
 * A:t,B:f  |   t    |    f       |            f        |
 * A:f,B:t  |   t    |    f       |            f        |
 * A:f,B:t  |   f    |    f       |            f        |
 * A:f,B:f  |   t    |    t       |            t        |
 * A:f,B:f  |   t    |    f       |            f        |
 * A:f,B:f  |   f    |    t       |            f        |
 * A:f,B:f  |   f    |    f       |            f        |
 *
 * 分析上述问题的回答结果，Q1(A) && Q2(B, A)为 false的情况下， A,B中至少存在一个传销。
 */

class Person
{
    const undercover = true;
    const pyramidSelling = false;
    private $id;
    private $type;

    public function __construct(int $id, bool $type)
    {
        $this->id = $id;
        $this->type = $type;
    }

    public function question1()
    {
        return $this->type === self::undercover ? true : (bool)rand(0, 1);
    }

    public function question2(Person $person)
    {
        return $this->type === self::undercover ? $person->type : (bool)rand(0, 1);
    }

    public function __toString()
    {
        return "UserId:{$this->id}, Type:" . ($this->type === true ? '卧底' : '传销');
    }
}

class ListNode
{
    public $person;
    public $prev;
    public $next;

    public function __construct(?Person $person, ?ListNode $prev, ?ListNode $next)
    {
        $this->person = $person;
        $this->prev = $prev;
        $this->next = $next;
    }
}

class WhoIsUndercover
{
    private function getPersons(int $num)
    {
        do {
            $more = 0;
            $hasPyramidSelling = false;
            $persons = [];
            for ($i = 1; $i <= $num; $i++) {
                $r = rand(0, 3);
                $more += $r ? 1 : -1;
                $hasPyramidSelling = $r == 0;
                $persons[] = new Person($i, (bool)$r);
            }
        } while ($more <= 0 || !$hasPyramidSelling);
        return $persons;
    }

    private function findUndercover(array $persons)
    {
        $header = new ListNode(new Person(0, false), null, null);
        $curr = $header;
        $max = sizeof($persons) % 2 ? sizeof($persons) - 2 : sizeof($persons) - 1;
        for ($i = 0; $i <= $max; $i++) {
            /** @var $person Person */
            $person = $persons[$i];
            if ($header->next) {
                if ($person->question2($curr->person)) {
                    $curr = $curr->next = new ListNode($person, $curr, null);
                } else {
                    $curr = $curr->prev;
                    $curr->next = null;
                }
            } else if ($person->question1()) {
                $curr = $curr->next = new ListNode($person, $header, null);
            }
        }
        return (!$header->next) ? $persons[$max + 1] : $header->next->person;
    }

    public function main()
    {
        for ($i = 0; $i < 10000; $i++) {
            $persons = $this->getPersons(rand(100, 200));
            if (strpos((string)$this->findUndercover($persons), '卧底') === false)
                echo "failed";
        }
        echo "success";
    }
}

(new WhoIsUndercover())->main();
